#include "BitcoinExchange.hpp"

void	validate_date(std::string const & date)
{
	if (date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("Invalid date format");
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!isdigit(date[i]))
			throw std::invalid_argument("Invalid date format");
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		throw std::invalid_argument("Invalid date format");
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year % 4 == 0 && month == 2 && day > 29)
		throw std::invalid_argument("Invalid date format");
	if (year % 4 != 0 && month == 2 && day > 28)
		throw std::invalid_argument("Invalid date format");
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			throw std::invalid_argument("Invalid date format");
		if (day == 0)
			throw std::invalid_argument("Invalid date format");
	}
	else
	{
		if (day > 31)
			throw std::invalid_argument("Invalid date format");
		if (day == 0)
			throw std::invalid_argument("Invalid date format");
	}
}

void	validate_quantity(std::string const & quantity)
{
	std::cout << "|" << quantity << "|" << std::endl;
	if (quantity[0] != ' ')
		throw std::invalid_argument("Invalid quantity format");
	for (unsigned int i = 1; i < quantity.length(); i++)
	{
		if (!isdigit(quantity[i]) && quantity[i] != '.')
			throw std::invalid_argument("Invalid quantity format");
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./ex00" << std::endl;
		return (1);
	}
	BitcoinExchange		exchange;
	std::string		line;
	std::ifstream	ifs(av[1]);
	int i = 1;
	while (getline(ifs, line))
	{
		try
		{
			validate_date(line.substr(0, '|'));
			validate_quantity(line.substr(line.find('|') + 1));
		}
		catch (std::invalid_argument & e)
		{
			std::cout << "Line " << i << ": " << e.what() << std::endl;
			continue ;
		}
		exchange.searchMap(line);
		i++;
	}
	return (0);
}
