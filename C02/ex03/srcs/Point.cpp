#include "../inc/Point.hpp"

Point::Point() : x(0.00f), y(0.00f)
{
}

Point::Point( float x, float y ) : x(x), y(y)
{
}

Point::~Point()
{
}

Point &Point::operator=(Point const &rhs)
{
	this->x = rhs.getX();
	this->y = rhs.getY();
	return *this;
}

Point::Point(Point const &src)
{
	*this = src;
}

float Point::getX() const
{
	return this->x.toFloat();
}

float Point::getY() const
{
	return this->y.toFloat();
}

void Point::print() const
{

	std::cout << "Point(" << x.toFloat() << ", " << y.toFloat() << ")" << std::endl;
}
