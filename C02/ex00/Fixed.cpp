#include "Fixed.hpp"

Fixed :: Fixed ( void )
{
	value = 0;
	std :: cout << "Default constructor called" << std :: endl;
}

Fixed :: Fixed ( const Fixed & src )
{
	std :: cout << "Copy constructor called" << std :: endl;
	*this = src;
}

Fixed :: ~Fixed ( void )
{
	std :: cout << "Destructor called" << std :: endl;
}

Fixed &	Fixed :: operator= ( const Fixed & rhs )
{
	std :: cout << "Assignation operator called" << std :: endl;
	this -> value = rhs.getRawBits();
	return *this;
}

int		Fixed :: getRawBits ( void ) const
{
	std :: cout << "getRawBits member function called" << std :: endl;
	return value;
}

void	Fixed :: setRawBits ( int const raw )
{
	value = raw;
}
