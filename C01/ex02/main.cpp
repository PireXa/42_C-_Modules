#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::string string = str;

	std::cout << "string Address:		";
	std::cout << &str << std::endl;
	std::cout << "stringPTR Address:	";
	std::cout << stringPTR << std::endl;
	std::cout << "stringREF Address:	";
	std::cout << &stringREF << std::endl;
	std::cout << "string Address:		";
	std::cout << &string << std::endl << std::endl;

	std::cout << "string Value:		";
	std::cout << str << std::endl;
	std::cout << "stringPTR Value:	";
	std::cout << *stringPTR << std::endl;
	std::cout << "stringREF Value:	";
	std::cout << stringREF << std::endl;
	std::cout << "string Value:		";
	std::cout << string << std::endl;
}
