#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal **animals = new Animal*[6];
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < 6; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 6; i++)
		delete animals[i];
	delete [] animals;
	return 0;
}
