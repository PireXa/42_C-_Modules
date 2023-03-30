#include "../inc/bsp.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
	Fixed l1 = ((b.getY() - c.getY()) * (p.getX() - c.getX()) + (c.getX() - b.getX()) * (p.getY() - c.getY())) / ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
	Fixed l2 = ((c.getY() - a.getY()) * (p.getX() - c.getX()) + (a.getX() - c.getX()) * (p.getY() - c.getY())) / ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
	Fixed l3 = Fixed(1) - l1 - l2;

	std::cout << "l1: " << l1 << std::endl;
	std::cout << "l2: " << l2 << std::endl;
	std::cout << "l3: " << l3 << std::endl;
	if (l1 >= 0 && l2 >= 0 && l3 >= 0 && l1 + l2 + l3 == 1)
		return true;
	return false;
}
