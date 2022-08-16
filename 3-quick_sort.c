#include "sort.h"
void quick_sort(int *array, size_t size);
size_t array_size;
/**
 * quick_sort - sorts an array of integers in ascending order using
 * Quick sort
 * @array: array of integer to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	extern size_t array_size;
	array_size = size - 1;
	quick_sort_algo(array, 0, array_size);
}
/**
 * quick_sort_algo - quick sort
 * @arr: array to sort
 * @low: low point of partition
 * @high: high point of partition
 * Return: void
 */
void quick_sort_algo(int *array, int low, int high)
{
	int array_part;

	if (low < high)
	{
		array_part = partition(array, low, high);
		quick_sort_algo(array, low, array_part - 1);
		quick_sort_algo(array, array_part + 1, high);
	}
}
/**
 * partition - partitions an array by taking the last element as pivot,
 * and places all element smaller than pivot to the left side and all element
 * greater than pivot to the right side
 * @array: array to partition
 * @low: the low of partition
 * @high: the high of partition
 * Return: the correct position of partition
 */
int partition(int *array, int low, int high)
{
	extern size_t array_size;
	int pivot = array[high];
	int i = low - 1;
	int j;

	
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			_swap((array + i), (array + j));
			print_array(array, array_size + 1);
		}
	}
	_swap((array + i + 1), (array + high));
	return(i + 1);
}
