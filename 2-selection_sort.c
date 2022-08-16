#include "sort.h"

/**
 * selection_sort - sorts an array (int) in ascending order
 *
 * Description: 'Selection sort algorithm' compares current elem with all
 * other of the array if greater swap then continue with the present elem
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t index, i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
			if (array[index] > array[j])
				index = j;

		if (index != i)
		{
			_swap(&array[index], &array[i]);
			print_array(array, size);
		}
	}
}
