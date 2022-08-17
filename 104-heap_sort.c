#include "sort.h"

/**
 * max_heapify - turns an array into a heap tree
 * @array: array to turn into heap
 * @size: size of array
 * @n: size of the subtree
 * @index: index of the subtree in the heap
 */
void max_heapify(int *array, size_t size, size_t n, size_t index)
{
	size_t pi, li, ri;
	int tmp;

	/* binary tree copy cat */
	pi = index;
	li = (index * 2) + 1;
	ri = (index * 2) + 2;

	if (li < n && array[li] > array[pi])
		pi = li;
	if (ri < n && array[ri] > array[pi])
		pi = ri;
	if (pi != index)
	{
		tmp = array[pi];
		array[pi] = array[index];
		array[index] = tmp;
		print_array(array, size);
		/* repeat on the ne sifted down index */
		max_heapify(array, size, n, pi);
	}
}

/**
 * heap_sort - sorts an array following the Heap sort algorithm
 * @array: array of ints to sort
 * @size: size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	int tmp, i;

	if (!array || size < 2)
		return;

	/* Build up a max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, (size_t)i);

	/* remove head node and reorganizing */
	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		if (i != 0)
			print_array(array, size);
		max_heapify(array, size, (size_t)i, 0);
	}
}
