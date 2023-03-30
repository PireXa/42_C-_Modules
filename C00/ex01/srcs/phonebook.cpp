#include "../inc/header.hpp"

PhoneBook::PhoneBook()
{
	this->i = 0;
	for (int i = 0; i < 8; i++)
		this->contact[i] = Contact();
}

void	PhoneBook::add()
{
	this->contact[this->i].set_info(this->i);
}

void	PhoneBook::print_phonebook()
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->contact[i].get_first_name().empty())
			break ;
		std::cout << std::setw(10) << i << "|";
		if (this->contact[i].get_first_name().length() > 10)
			std::cout << this->contact[i].get_first_name().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[i].get_first_name() << "|";
		if (this->contact[i].get_last_name().length() > 10)
			std::cout << this->contact[i].get_last_name().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[i].get_last_name() << "|";
		if (this->contact[i].get_nickname().length() > 10)
			std::cout << this->contact[i].get_nickname().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[i].get_nickname();
		std::cout << std::endl;
	}
}

void	PhoneBook::search()
{
	int	index;
	print_phonebook();
	std::cout << "Enter index: ";
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (index < 0 || index > 7 || this->contact[index].get_first_name().empty())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "first name: " << this->contact[index].get_first_name() << std::endl;
	std::cout << "last name: " << this->contact[index].get_last_name() << std::endl;
	std::cout << "nickname: " << this->contact[index].get_nickname() << std::endl;
	std::cout << "phone number: " << this->contact[index].get_phone_number() << std::endl;
	std::cout << "darkest secret: " << this->contact[index].get_darkest_secret() << std::endl;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}
