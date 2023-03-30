#include "../inc/header.hpp"

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

std::string	Contact::get_last_name()
{
	return (this->last_name);
}

std::string	Contact::get_nickname()
{
	return (this->nickname);
}

std::string	Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}

void	Contact::set_info(int &i)
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, this->first_name);
	while (this->get_first_name().empty())
	{
		std::cout << "Invalid first name" << std::endl;
		std::cout << "Enter first name: ";
		std::getline(std::cin, this->first_name);
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, this->last_name);
	while (this->get_last_name().empty())
	{
		std::cout << "Invalid last name" << std::endl;
		std::cout << "Enter last name: ";
		std::getline(std::cin, this->last_name);
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->nickname);
	while (this->get_nickname().empty())
	{
		std::cout << "Invalid nickname" << std::endl;
		std::cout << "Enter nickname: ";
		std::getline(std::cin, this->nickname);
	}
	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->phone_number);
	while (!is_string_digit(this->get_phone_number()) || this->get_phone_number().empty())
	{
		std::cout << "Invalid phone number" << std::endl;
		std::cout << "Enter phone number: ";
		std::getline(std::cin, this->phone_number);
	}
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, this->darkest_secret);
	while (this->get_darkest_secret().empty())
	{
		std::cout << "Invalid darkest secret" << std::endl;
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, this->darkest_secret);
	}
	if (i == 7)
		i = 0;
	else
		i++;
}
