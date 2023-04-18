#include "Span.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(Span const & src) : _n(src._n), _v(src._v)
{
}

Span::~Span()
{
}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_v = rhs._v;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() == _n)
		throw SpanFullException();
	_v.push_back(n);
}

void Span::addRangeNumbers(int min, int max)
{
	if (min > max)
	{
		int tmp = min;
		min = max;
		max = tmp;
	}
	if ((unsigned int)(max - min + 1) > _n)
		throw SpanFullException();
	for (int i = min; i <= max; i++)
		_v.push_back(i);
}

void Span::addRandomNumbers(int min, int max, int n)
{
	srand(time(NULL));
	if (min > max)
	{
		int tmp = min;
		min = max;
		max = tmp;
	}
	if ((unsigned int)n > _n)
		throw SpanFullException();
	for (int i = 0; i < n; i++)
		_v.push_back(rand() % (max - min + 1) + min);
}

int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw SpanEmptyException();
	std::vector<int> v(_v);
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (unsigned int i = 2; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] < min)
			min = v[i] - v[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw SpanEmptyException();
	std::vector<int> v(_v);
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}

const char* Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

const char* Span::SpanEmptyException::what() const throw()
{
	return "Span is empty";
}
