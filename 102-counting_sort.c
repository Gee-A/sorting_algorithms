#include "sort.h"
void h_counting_sort(int *array, size_t size, int k);

/**
 * counting_sort - an implemetation of counting sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max;
	size_t i;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size && array[i]; i++)
		if (array[i] > max)
			max = array[i];
	h_counting_sort(array, size, max + 1);
}

/**
 * h_counting_sort - counting sort helper function
 * @array: the array to sort
 * @size: size of the array
 * @k: size of the count array to be created
 */
void h_counting_sort(int *array, size_t size, int k)
{
	int i, *array_copy, *count;
	size_t j;

	count = malloc(sizeof(int) * k);
	if (!count)
		return;
	for (i = 0; i < k; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		++count[array[j]];
	for (i = 1; i < k; i++)
		count[i] += count[i - 1];
	print_array(count, k);

	array_copy = malloc(sizeof(int) * size);
	if (!array_copy)
		return;
	for (i = size - 1; i >= 0; i--)
		array_copy[--count[array[i]]] = array[i];

	for (j = 0; j < size; j++)
		array[j] = array_copy[j];

	free(count);
	free(array_copy);
}
