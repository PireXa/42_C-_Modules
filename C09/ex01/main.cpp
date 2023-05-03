//
// Created by fde-albe on 4/26/23.
//

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>


int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	unsigned int i = 0;
	char *value;
	std::stack<int> stack;
	while (av[1][i])
	{
		if (av[1][i] == ' ')
		{
			i++;
			continue ;
		}
		if (std::isdigit(av[1][i]))
		{
			value = &av[1][i];
			while (std::isdigit(av[1][i]))
				i++;
			stack.push(std::atoi(value));
		}
		else if (av[1][i] == '+' || av[1][i] == '-' || av[1][i] == '*' || av[1][i] == '/' || av[1][i] == '%')
		{
			if (stack.size() < 2)
			{
				std::cout << "Error" << std::endl;
				return 1;
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (av[1][i] == '+')
				stack.push(a + b);
			else if (av[1][i] == '-')
				stack.push(a - b);
			else if (av[1][i] == '*')
				stack.push(a * b);
			else if (av[1][i] == '/')
			{
				if (b == 0)
				{
					std::cout << "Error" << std::endl;
					return 1;
				}
				stack.push(a / b);
			}
			else if (av[1][i] == '%')
				stack.push(a % b);
			i++;
		}
		else
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	if (stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	std::cout << stack.top() << std::endl;
	return 0;
}