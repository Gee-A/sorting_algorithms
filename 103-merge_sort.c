#include "sort.h"

void merge_recursion(int *arr, int *array, size_t left, size_t right);
void merge_subarray(int *arr, int *array, size_t left, size_t mid,
				size_t right);
/**
 * merge_sort - sorts an array (int) in ascending order
 *
 * Description: '(top down)Merge sort algorithm' recursively divides list
 * into smaller sublists until the sublists are trivially sorted, and then
 * merges the sublist while returning up the call chain.
 *
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);
	merge_recursion(arr, array, 0, size);
	free(arr);
}

/**
 * merge_recursion - recursive function that divides then merge array
 * @arr: array.copy()
 * @array: array to sort
 * @left: index of the leftmost element
 * @right: index of the rightmost element
 */
void merge_recursion(int *arr, int *array, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = (right + left) / 2;
		merge_recursion(arr, array, left, mid);
		merge_recursion(arr, array, mid, right);
		merge_subarray(arr, array, left, mid, right);
	}
}

/**
 * merge_subarray - the conquer function merges subarray
 * @arr:
 * @array: array to sort
 * @left: index of the leftmost element
 * @mid: index of the middle element
 * @right: index of the rightmost element
 */
void merge_subarray(int *arr, int *array, size_t left, size_t mid,
				size_t right)
{
	size_t index = 0, i, j;

	printf("Merging...\n[left]: ");
	/* ensures that array shift rightly */
	print_array((array + left), mid - left);
	printf("[right]: ");
	print_array((array + mid), right - mid);

	for (i = left, j = mid; i < mid && j < right; index++)
	{
		if (array[i] < array[j])
			arr[index] = array[i++];
		else
			arr[index] = array[j++];
	}
	while (i < mid)
		arr[index++] = array[i++];
	while (j < right)
		arr[index++] = array[j++];

	for (i = left, index = 0; i < right; i++, index++)
		array[i] = arr[index];

	printf("[Done]: ");
	print_array((array + left), right - left);
}
