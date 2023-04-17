#ifndef ITER_H
#define ITER_H

#include <iostream>

template<typename T> void iter(T *arr, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template<typename T> void printvalue(T const &value)
{
	std::cout << value << std::endl;
}

#endif
