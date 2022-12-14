#include "sort.h"
void quick_sort_algo(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using
 * Quick sort
 * @array: array of integer to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	if (size <= 0)
		return;

	quick_sort_algo(array, 0, (int)size - 1, size);
}
/**
 * quick_sort_algo - quick sort
 * @array: array to sort
 * @low: low point of partition
 * @high: high point of partition
 * @size: size of the array
 * Return: void
 */
void quick_sort_algo(int *array, int low, int high, size_t size)
{
	int array_part;

	if (low < high)
	{
		array_part = partition(array, low, high, size);
		quick_sort_algo(array, low, array_part - 1, size);
		quick_sort_algo(array, array_part + 1, high, size);
	}
}
/**
 * partition - partitions an array by taking the last element as pivot,
 * and places all element smaller than pivot to the left side and all elem
 * greater than pivot to the right side
 * @array: array to partition
 * @low: the low of partition
 * @high: the high of partition
 * @size: size of the array
 * Return: the correct position of partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int tmp, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
