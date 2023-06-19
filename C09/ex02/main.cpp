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

int check_double(char **sequence, int nb)
{
	int i = 0;
	int j = 0;
	while (i < nb)
	{
		j = i + 1;
		while (j < nb)
		{
			if (std::strcmp(sequence[i], sequence[j]) == 0)
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

int check_sequence(char **sequence, int nb)
{
	if (check_double(sequence, nb))
	{
		std::cout << "Error: double value in sequence" << std::endl;
		return 1;
	}
	return 0;
}

void string_to_vector(char **sequence, std::vector<int> &v)
{
	int i = 0;
	while (*++sequence)
	{
		std::stringstream ss(sequence[i]);
		int val;
		ss >> val;
		v.push_back(val);
	}
}

void string_to_deque(char **sequence, std::deque<int> &d)
{
	int i = 0;
	while (*++sequence)
	{
		std::stringstream ss(sequence[i]);
		int val;
		ss >> val;
		d.push_back(val);
	}
}

void print_vector(std::vector<int> &v)
{
	for (long unsigned int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void print_deque(std::deque<int> &d)
{
	for (long unsigned int i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;
}

void	merge_vector(std::vector <int> &v, std::vector <int> &left, std::vector <int> &right)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int left_size = left.size();
	int right_size = right.size();
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			v[k++] = left[i++];
		else
			v[k++] = right[j++];
	}
	while (i < left_size)
		v[k++] = left[i++];
	while (j < right_size)
		v[k++] = right[j++];
}

void	merge_insertion_sort_vector(std::vector<int> &v, int nb)
{
	if (nb <= 1)
		return;
	int mid = nb / 2;
	std::vector<int> left;
	std::vector<int> right;
	for (int i = 0; i < mid; i++)
		left.push_back(v[i]);
	for (int i = mid; i < nb; i++)
		right.push_back(v[i]);
	merge_insertion_sort_vector(left, mid);
	merge_insertion_sort_vector(right, nb - mid);
	merge_vector(v, left, right);
}

void merge_deque(std::deque <int> &d, std::deque <int> &left, std::deque <int> &right)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int left_size = left.size();
	int right_size = right.size();
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			d[k++] = left[i++];
		else
			d[k++] = right[j++];
	}
	while (i < left_size)
		d[k++] = left[i++];
	while (j < right_size)
		d[k++] = right[j++];
}

void	merge_insertion_sort_deque(std::deque<int> &d, int nb)
{
	if (nb <= 1)
		return;
	int mid = nb / 2;
	std::deque<int> left;
	std::deque<int> right;
	for (int i = 0; i < mid; i++)
		left.push_back(d[i]);
	for (int i = mid; i < nb; i++)
		right.push_back(d[i]);
	merge_insertion_sort_deque(left, mid);
	merge_insertion_sort_deque(right, nb - mid);
	merge_deque(d, left, right);
}

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cout << "Usage: " << av[0] << " nb .. nb" << std::endl;
		return 1;
	}
	if (check_sequence(av, ac))
		return 1;
	std::cout << "Before:	";
	print_sequence(av);


	//Vector
	std::vector<int> v;
	string_to_vector(av, v);

	// Start measuring time
	clock_t start = clock();
	merge_insertion_sort_vector(v, ac - 1);
	clock_t end = clock();
	double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
	std::cout << std::setprecision(6) << std::fixed;
	std::cout << "After:	";
	print_vector(v);
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << elapsed_time << " us" << std::endl;

	//Double ended queue
	std::deque <int> d;
	string_to_deque(av, d);

	// Start measuring time
	start = clock();
	merge_insertion_sort_deque(d, ac - 1);
	end = clock();
	elapsed_time = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << elapsed_time << " us" << std::endl;

	return 0;
}
