#include "replace.hpp"

int main(int ac, char **av)
{
	int replace_index = 0;
	if (ac != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string read;
	std :: ifstream ifs(av[1]);
	if (!ifs)
	{
		std::cout << "Error: file not found" << std::endl;
		return (1);
	}
	if (!ifs.is_open())
	{
		std::cout << "Error: File not found or wrong permissions" << std::endl;
		return 1;
	}
	if (ifs.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Error: File is empty" << std::endl;
		return 1;
	}
	std :: ofstream ofs;
	ofs.open(((std::string)av[1] + ".replace").c_str());
	while (getline(ifs, read))
	{
		while ((long unsigned int)replace_index <= read.length() && read.find(s1, replace_index) != std::string::npos)
		{
			read = replace(read, s1, s2, replace_index);
		}
		replace_index = 0;
		ofs << read << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}
