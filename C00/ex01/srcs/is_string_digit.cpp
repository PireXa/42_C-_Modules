#include "../inc/header.hpp"

bool	is_string_digit(std :: string str)
{
	while (!str.empty())
	{
		if (!isdigit(str[0]))
			return (false);
		str.erase(0, 1);
	}
	return (true);
}
