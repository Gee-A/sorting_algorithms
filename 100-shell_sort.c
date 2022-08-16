#include "sort.h"

/**
 * shell_sort - sorts an array (int) in ascending order.
 *
 * Description: 'Shell sort algorithm' using knuth is an in-place comparison
 * sort. The method start by sorting pairs of elements far apart from each
 * other, then progressively reducing the gap between elem compared.
 *
 * @array: array of integers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	/**
	 * using the knuth sequence (n + 1) = n * 3 + 1
	 * other case could be taking the array size at start
	 */
	do {
		gap = gap * 3 + 1;
	} while (gap < size);

	/* going in reverse */
	while ((gap = (gap - 1) / 3) > 0)
	{
		for (i = gap; i < size; i++)
		{
			/* the swap case: '<= because shellsort is not stable' */
			tmp = array[i];
			for (j = i; j >= gap && tmp <= array[j - gap]; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
