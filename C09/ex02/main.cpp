//
// Created by fde-albe on 5/3/23.
//

#include "PmergeMe.hpp"

void print_sequence(char **av)
{
	while (*++av)
		std::cout << *av << " ";
	std::cout << std::endl;
}

int check_sequence(char **sequence, int nb)
{
	if (check_double(sequence, nb))
	{
		std::cout << "Error: double value in sequence" << std::endl;
		exit(1);
	}
}

void merge(char **sequence, int nb1, int nb2)
{
	char **tmp = new char*[nb1 + nb2];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < nb1 && j < nb2)
	{
		if (strcmp(sequence[i], sequence[nb1 + j]) < 0)
			tmp[k++] = sequence[i++];
		else
			tmp[k++] = sequence[nb1 + j++];
	}
	while (i < nb1)
		tmp[k++] = sequence[i++];
	while (j < nb2)
		tmp[k++] = sequence[nb1 + j++];
	for (int i = 0; i < nb1 + nb2; i++)
		sequence[i] = tmp[i];
	delete[] tmp;
}

void merge_insertion_sort(char **sequence, int nb)
{
	if (nb <= 1)
		return;
	if (nb == 2)
	{
		if (strcmp(sequence[0], sequence[1]) > 0)
			std::swap(sequence[0], sequence[1]);
		return;
	}
	int mid = nb / 2;
	merge_insertion_sort(sequence, mid);
	merge_insertion_sort(sequence + mid, nb - mid);
	merge(sequence, mid, nb - mid);
}

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cout << "Usage: " << av[0] << " nb .. nb" << std::endl;
		return 1;
	}
	check_sequence(av);
	print_sequence(av);
	merge_insertion_sort(av + 1, ac - 1);
	print_sequence(av);
	return 0;
}