#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact	contact[8];
		int			i;
	public:
		PhoneBook();
		void	add();
		void	print_phonebook();
		void	search();
};

#endif
