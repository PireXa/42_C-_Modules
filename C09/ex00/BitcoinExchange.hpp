#ifndef	BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <ctime>
#include <cstring>

struct BitcoinExchange
{
	private:
		std::map<std::string, double>	exchange;
	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string const & name, double const & price);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);
		BitcoinExchange &	operator=(BitcoinExchange const & rhs);
		void			setMap();
		void			printMap();
		void			searchMap(std::string const & search_string);
};

#endif
