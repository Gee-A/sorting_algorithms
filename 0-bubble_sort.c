#include "sort.h"

/**
 * bubble_sort - sorts an array (int) in ascending order.
 *
 * Description: 'Bubble sort algorithm' compares the first two number if
 * greater swap appropriately then go on to the next till all are sorted.
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				_swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
