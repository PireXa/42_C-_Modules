#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		Point(float x, float y);
		~Point();
		Point(Point const &src);
		Point &operator=(Point const &rhs);
		float getX() const;
		float getY() const;
		void setX(float x);
		void setY(float y);
		void setXY(float x, float y);
		void print() const;
};

#endif
