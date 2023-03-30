#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int				value;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		~Fixed();
		Fixed &operator=(const Fixed &rhs);
		Fixed (const int value);
		Fixed (const float value);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int 	toInt() const;
		float 	toFloat() const;

		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;

		Fixed operator+(const Fixed &rhs);
		Fixed operator-(const Fixed &rhs);
		Fixed operator*(const Fixed &rhs);
		Fixed operator/(const Fixed &rhs);

		Fixed &operator++() { value++; return *this; };
		Fixed &operator--() { value--; return *this; };
		Fixed operator++(int) { Fixed tmp(*this); operator++(); return tmp; };
		Fixed operator--(int) { Fixed tmp(*this); operator--(); return tmp; };

		static Fixed &min(Fixed &a, Fixed &b) { return a < b ? a : b; };
		static const Fixed &min(const Fixed &a, const Fixed &b) { return a < b ? a : b; };
		static Fixed &max(Fixed &a, Fixed &b) { return a > b ? a : b; };
		static const Fixed &max(const Fixed &a, const Fixed &b) { return a > b ? a : b; };
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif