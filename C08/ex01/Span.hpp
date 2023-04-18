#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span/* : public std::exception*/
{
	private:
		unsigned int    _n;
		std::vector<int> _v;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const & src);
		~Span();
		Span & operator=(Span const & rhs);
		void addNumber(int n);
		void addRangeNumbers(int min, int max);
		void addRandomNumbers(int min, int max, int n);
		int shortestSpan();
		int longestSpan();
		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class SpanEmptyException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
