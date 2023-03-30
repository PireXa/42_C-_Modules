#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "debugggggggggggg" << std::endl;
}

void Harl::info(void)
{
	std::cout << "infooooooooooooo" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "warninggggggggggg" << std::endl;
}

void Harl::error(void)
{
	std::cout << "errorrrrrrrrrrrrr" << std::endl;
}

void Harl::complain(std::string level)
{
	std::cout << "Harl: ";
	std::string functions[4] = {"debug", "info", "warning", "error"};
	void (Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level == functions[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "I don't know how to complain about " << level << std::endl;
}
