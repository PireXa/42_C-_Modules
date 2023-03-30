#include "replace.hpp"

std::string	replace(std::string read, std::string find, std::string replace_str, int &replace_index)
{
	int tmp;
	std::string ret;
	ret = read.substr(0, read.find(find, replace_index));
	replace_index = ret.length();
	ret += replace_str;
	tmp = ret.length();
	ret += read.substr(read.find(find, replace_index) + find.length());
	replace_index = tmp;
	return (ret);
}
