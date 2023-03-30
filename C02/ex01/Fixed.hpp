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
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif