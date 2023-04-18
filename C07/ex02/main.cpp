#include "Array.hpp"

int main()
{
	Array<int> arr1;
	std::cout << "arr1 size: " << arr1.size() << std::endl;
	Array<int> arr2(5);
	std::cout << "arr2 size: " << arr2.size() << std::endl;
	Array<int> arr3(arr2);
	std::cout << "arr3 size: " << arr3.size() << std::endl;
	for (unsigned int i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << " ";
	std::cout << std::endl;
	Array<int> arr4;
	arr4 = arr3;
	std::cout << "arr4 size: " << arr4.size() << std::endl;
	for (unsigned int i = 0; i < arr4.size(); i++)
		std::cout << arr4[i] << " ";
	std::cout << std::endl;
	try
	{
		arr2[-5] = 1;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (unsigned int i = 0; i < arr2.size(); i++)
	{
		arr2[i] = i;
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
