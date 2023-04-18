#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T *_arr;
		unsigned int _size;
	public:
		Array(void) : _arr(NULL), _size(0) {}
		Array(unsigned int n) : _arr(new T[n]()), _size(n) {}
		Array(const Array &src) : _arr(new T[src._size]()), _size(src._size)
		{
			for (unsigned int i = 0; i < _size; i++)
				_arr[i] = src._arr[i];
		}
		Array &operator=(const Array &src)
		{
			if (this != &src)
			{
				delete[] _arr;
				_arr = new T[src._size]();
				_size = src._size;
				for (unsigned int i = 0; i < _size; i++)
					_arr[i] = src._arr[i];
			}
			return *this;
		}
		~Array(void) { delete[] _arr; }
		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("Index is out of range");
			return _arr[index];
		}
		unsigned int size(void) const { return _size; }
};

#endif
