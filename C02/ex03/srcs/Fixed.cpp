#include "../inc/Fixed.hpp"

Fixed :: Fixed ( void )
{
	value = 0;
}

Fixed :: Fixed ( const Fixed & src )
{
	*this = src;
}

Fixed :: ~Fixed ( void )
{
}

Fixed & Fixed :: operator= ( const Fixed & rhs )
{
	this -> value = rhs.getRawBits();
	return *this;
}

Fixed :: Fixed ( const int value )
{
	this -> value = value << fractionalBits;
}

Fixed :: Fixed ( const float value )
{
	this -> value = roundf(value * (1 << fractionalBits));
}

int 	Fixed :: toInt () const
{
	return value >> fractionalBits;
}

float 	Fixed :: toFloat () const
{
	return (float)value / (1 << fractionalBits);
}

int		Fixed :: getRawBits ( void ) const
{
	return value;
}

void	Fixed :: setRawBits ( int const raw )
{
	value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return out;
}

bool Fixed :: operator>(const Fixed &rhs) const { return value > rhs.value; }

bool Fixed :: operator<(const Fixed &rhs) const { return value < rhs.value; }

bool Fixed :: operator>=(const Fixed &rhs) const { return value >= rhs.value; }

bool Fixed :: operator<=(const Fixed &rhs) const { return value <= rhs.value; }

bool Fixed :: operator==(const Fixed &rhs) const { return value == rhs.value; }

bool Fixed :: operator!=(const Fixed &rhs) const { return value != rhs.value; }


Fixed Fixed ::operator+(const Fixed &rhs) { return Fixed(toFloat() + rhs.toFloat()); }

Fixed Fixed ::operator-(const Fixed &rhs) { return Fixed(toFloat() - rhs.toFloat()); }

Fixed Fixed ::operator*(const Fixed &rhs) { return Fixed(toFloat() * rhs.toFloat()); }

Fixed Fixed ::operator/(const Fixed &rhs) { return Fixed(toFloat() / rhs.toFloat()); }

