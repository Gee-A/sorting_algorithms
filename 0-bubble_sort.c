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
	size_t i, j;

	/**
	 * compares the first two number if and swap appropriately
	 * then go to the next until all are sorted.
	 */
	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
			if (array[j] > array[j + 1])
			{
				_swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
	}
}
