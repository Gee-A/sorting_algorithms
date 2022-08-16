#include "sort.h"
/**
 * bitonic_sort - sorts anarray of integers in ascending order using
 * Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array, size has to 2^k, where k >= 0,
 * this program doesn't check for that
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	bitonic_sort_algo(array, 0, size - 1, 1);
}
/**
 * bitonic_sort_algo - bitonic sort
 * @array: array to sort
 * @partition: the index of partition, the half of the list
 * @low: the low end of the partition
 * @direction: 1 signifies increasing order and 0 signifies decreasing
 * Return: void
 */
void bitonic_sort_algo(int *array, int low, int partition, int direction)
{
	int i;
	int count;

	if (partition > 1)
	{
		count = partition / 2;
		bitonic_sort_algo(array, low, count, 1);
		bitonic_sort_algo(array, low + count, partition, 0);
		for (i = low; i <= count; i++)
		{
			if (direction == (array[i] > array[count + i]))
				_swap((array + i), (array + count + i));
		}
		bitonic_sort_algo(array, low, partition, direction);
	}
}
