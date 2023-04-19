#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		if (mstack.empty())
			std::cout << RED"Stack is empty." << std::endl;
		mstack.push(5); std::cout << GREEN"Added one value." << std::endl;
		mstack.push(17); std::cout << "Added one value." << std::endl;
		std::cout << YELLOW"Value at the top: " RESET << mstack.top() << std::endl;

		mstack.pop(); std::cout << RED"Removed one value." << std::endl;
		std::cout << BLUE"Size: " RESET << mstack.size() << std::endl;

		mstack.push(3); std::cout << GREEN"Added one value." << std::endl;
		mstack.push(5); std::cout << "Added one value." << std::endl;
		mstack.push(737); std::cout << "Added one value." << std::endl;
		mstack.push(0);	std::cout << "Added one value." << std::endl;
		std::cout << BLUE"Size: " RESET << mstack.size() << std::endl;

		MutantStack<int>::iterator it_begin = mstack.begin();
		MutantStack<int>::iterator it_end = mstack.end();
		++it_begin;
		--it_begin;
		while (it_begin != it_end)
		{
			std::cout << *it_begin << std::endl;
			++it_begin;
		}
		std::stack<int> s(mstack);
		std::cout << YELLOW"Size of the copied stack: " RESET << s.size() << std::endl;
		mstack.pop(); std::cout << RED"Removed one value." << std::endl;
		mstack.pop(); std::cout << "Removed one value." << std::endl;
		MutantStack<int> mst(mstack);
		std::cout << YELLOW"Size of the copied mutant stack: " RESET << mst.size() << std::endl;
	}
	std::cout << "------------------" << std::endl;
	{
		std::list<int> normal_list;
		if (normal_list.empty())
			std::cout << RED"List is empty." << std::endl;
		normal_list.push_back(5); std::cout << GREEN"Added one value." << std::endl;
		normal_list.push_back(17); std::cout << "Added one value." << std::endl;
		std::cout << YELLOW"Value at the top: " RESET << normal_list.back() << std::endl;

		normal_list.pop_back(); std::cout << RED"Removed one value." << std::endl;
		std::cout << BLUE"Size: " RESET << normal_list.size() << std::endl;

		normal_list.push_back(3); std::cout << GREEN"Added one value." << std::endl;
		normal_list.push_back(5); std::cout << "Added one value." << std::endl;
		normal_list.push_back(737); std::cout << "Added one value." << std::endl;
		normal_list.push_back(0); std::cout << "Added one value." << std::endl;
		std::cout << YELLOW"Size: " RESET << normal_list.size() << std::endl;

		std::list<int>::iterator it_begin = normal_list.begin();
		std::list<int>::iterator it_end = normal_list.end();
		++it_begin;
		--it_begin;
		while (it_begin != it_end)
		{
			std::cout << *it_begin << std::endl;
			++it_begin;
		}
		std::list<int> lst(normal_list);
		std::cout << YELLOW"Size of the copied list: " RESET << lst.size() << std::endl;
	}
}
