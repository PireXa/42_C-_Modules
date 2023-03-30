#include "../inc/header.hpp"

int	main()
{
	std :: string		cmd;
	PhoneBook	phonebook;
	while (1)
	{
		std :: cout << "Enter command: ";
		std ::getline(std :: cin, cmd);
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else
			std :: cout << "Invalid command" << std :: endl;
	}
	return (0);
}
