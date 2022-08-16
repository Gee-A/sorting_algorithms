#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorithm
 *
 * @list: list of nodes to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *next;
	listint_t *prev;

	while (current != NULL)
	{
		next = current;
		prev = current->prev;
		current = current->next;

		while (prev != NULL && prev->n > next->n)
		{
			next = backward_swap(&next, list);
			print_list(*list);
			prev = next->prev;
		}
	}
}
