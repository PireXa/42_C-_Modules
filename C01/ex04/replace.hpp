#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <unistd.h>

std::string	replace(std::string read, std::string find, std::string replace_str, int &replace_index);

#endif