#include "sort.h"
size_t array_size;
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
	array_size = size;
	if (array == NULL)
		return;

	bitonic_sort_algo(array, 0, array_size, 1);
}
/**
 * bitonic_sort_algo - bitonic sort
 * @array: array to sort
 * @low: lower index
 * @high: higher index
 * @direction: direction
 * Return: void
 */
void bitonic_sort_algo(int *array, int low, int high, int direction)
{
	int k;

	if (high > 2)
	{
		k = high / 2;
		bitonic_sort_algo(array, low, k, 1);
		bitonic_sort_algo(array, low + k, k, 0);
		bitonic_merge(array, low, high, direction);
	}
}
/**
 * bitonic_merge - bitonic sort
 * @array: array to sort
 * @partition: the index of partition, the half of the list
 * @low: the low end of the partition
 * @direction: 1 signifies increasing order and 0 signifies decreasing
 * Return: void
 */
void bitonic_merge(int *array, int low, int count, int direction)
{
	int i;
	int k;
	char *dir;
	char *sep = "";

	if (direction == 1)
		dir = "UP";
	else if (direction == 0)
		dir = "DOWN";
	printf("Merging [%d/%ld] (%s):\n", count, array_size, dir);
	for (i = low; i < count; i++)
	{
		printf("%d%s\n", array[i], sep);
		sep = ",";
	}
	if (count > 1)
	{
		k = count / 2;
		for (i = low; i < (low + k); i++)
		{
			if (direction == (array[i] > array[k + i]))
				_swap((array + i), (array + k + i));
		}
		bitonic_merge(array, low, k, direction);
		bitonic_merge(array, low + k, k, direction);
	}
	printf("Result [%d/%ld] (%s):\n", count, array_size, dir);
	for (i = low; i < count; i++)
	{
		printf("%d%s\n", array[i], sep);
		sep = ",";
	}
}
