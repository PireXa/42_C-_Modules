#include "easyfind.hpp"

int main()
{
	int random;
	std::vector<int> v;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		random = rand() % 30;
		v.push_back(random);
	}
	std::cout << "Vector container: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	try
	{
		std::cout << *easyfind(v, 5) << std::endl;
		std::cout << *easyfind(v, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
		std::cout << "Value not found on vector." << std::endl;
	}
	return 0;
}
