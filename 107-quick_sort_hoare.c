#include "sort.h"

int partition(int *array, size_t lower_b, size_t upper_b);
void quicksort_recursion(int *array, size_t lower_b, size_t upper_b,
			size_t size);

/**
 * quick_sort_hoare - sorts an array (int) in ascending order
 *
 * Description: '(Hoare)Quick sort algorithm' is a D&C algorithm that works by
 * selecting a pivot(in this case the last element) from the array and
 * partitioning the other elements into two sub-arrays base on comparison.
 *
 * @array: array of integers
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort_recursion(array, 0, size - 1, size);
}

/**
 * quicksort_recursion - partition and divides array into subarray
 * @array: array of integers
 * @lower_b: lower bound of the array
 * @upper_b: upper bound of the array
 * @size: size of the array
 */
void quicksort_recursion(int *array, size_t lower_b, size_t upper_b,
			size_t size)
{
	size_t pos;

	if (lower_b < upper_b)
	{
		pos = partition(array, lower_b, upper_b);
		print_array(array, size);
		quicksort_recursion(array, lower_b, pos - 1, size);
		quicksort_recursion(array, pos, upper_b, size);
	}
}

/**
 * partition - sorts array such that integers less than the pivot are to the
 * left or the pivot position while greater to the right
 * @array: array of integers
 * @lower_b: lower bound of the array
 * @upper_b: upper bound of the array
 *
 * Return: sorted position of the pivot in the array.
 */
int partition(int *array, size_t lower_b, size_t upper_b)
{
	int pivot = array[upper_b];
	size_t i = lower_b - 1;
	size_t j = upper_b + 1;

	while (1)
	{
		do {
			i += 1;
		} while (array[i] < pivot);
		do {
			j -= 1;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);
		if (i != j)
			_swap(&array[i], &array[j]);
	}
	return (0);
}
