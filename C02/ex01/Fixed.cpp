#include "Fixed.hpp"

Fixed::Fixed ( void )
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator= ( const Fixed & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = rhs.getRawBits();
	return *this;
}

Fixed::Fixed ( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << fractionalBits;
}

Fixed::Fixed ( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << fractionalBits));
}

int 	Fixed::toInt () const
{
	return value >> fractionalBits;
}

float 	Fixed::toFloat () const
{
	return (float)value / (1 << fractionalBits);
}

int		Fixed::getRawBits ( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits ( int const raw )
{
	value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return out;
}
