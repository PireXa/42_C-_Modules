#include "../inc/bsp.hpp"

int  main()
{
	Point a;
	Point b(1.0f, 0.0f);
	Point c(3.0f, 0.0f);
	Point d(b);
	Point e(2.00f, 2.00f);

//	std::cout << "a: ";
//	a.print();
	std::cout << "b: ";
	b.print();
	std::cout << "c: ";
	c.print();
//	std::cout << "d: ";
//	d.print();
	std::cout << "e: ";
	e.print();

	Point p(1.66f, 1.08f);
	std::cout << "p: ";
	p.print();
	if (bsp(b, c, e, p))
		std::cout << "p is inside the triangle bce" << std::endl;
	else
		std::cout << "p is outside the triangle bce" << std::endl;
	return 0;
}
