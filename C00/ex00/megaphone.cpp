#include <iostream>

int main(int ac, char **av)
{
	int i = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < ac)
	{
		for (int j = 0; av[i][j]; j++)
			std::cout << (char)toupper(av[i][j]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
