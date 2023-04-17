#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <stdexcept>
#include <cmath>
#include <limits>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();
		static char		_char;
		static int		_int;
		static float	_float;
		static double	_double;
		static int 		_checkchar;
		static int 		_checkint;
		static int 		_checkfloat;
	public:
		static void convert_from_char(std::string const &str);
		static void convert_from_int(std::string const &str);
		static void convert_from_float(std::string const &str);
		static void convert_from_double(std::string const &str);
		static void convert(std::string const &cpp_literal);
		static void show_values();
		static int getLiteralType(const std::string &str);
		class InvalidInput : std::exception
		{
		public:
			const char *what() const throw();
		};
};

#endif
