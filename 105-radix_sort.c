#include "sort.h"

void count_sort(int *array, size_t size, int pos);

/**
 * radix_sort - sorts an array (int) in ascending order.
 *
 * Description: '(LSD)Radix sort algorithm' is a non-comparative sorting
 * algorithm. It avoids comparison by creating and distributing elements into
 * buckets according to their radix (base).
 * LSD: least significant digit (leveraging on counting sort).
 *
 * @array: array of integers
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int pos, max;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (pos = 1; max / pos > 0; pos *= 10)
	{
		count_sort(array, size, pos);
		print_array(array, size);
	}
}

/**
 * count_sort - sorts an array (ints) in ascending order using the Counting
 * sort algorithm.
 * @array: array of integers
 * @size: size of array
 * @pos: the digit position in consideration
 */
void count_sort(int *array, size_t size, int pos)
{
	size_t i;
	int j, *array_copy, count[10] = {0};

	array_copy = malloc(sizeof(int) * size);
	if (!array_copy)
		return;

	for (i = 0; i < size; i++)
		++count[(array[i] / pos) % 10];

	/* here, k = 9 (being max of base 10) */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	/* starting from last index to ensure stable sort */
	for (j = size - 1; j >= 0; j -= 1)
		array_copy[--count[(array[j] / pos) % 10]] = array[j];
	for (i = 0; i < size; i++)
		array[i] = array_copy[i];
	free(array_copy);
}
