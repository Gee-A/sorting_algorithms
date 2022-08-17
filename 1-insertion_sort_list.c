#include "sort.h"

/**
 * backward_swap - swap a nde in a list with previous node provided that the
 * previous node is not null
 * @node: the node to swap
 * @head: head of the list
 * Return: the pointer to the node
 */
listint_t *backward_swap(listint_t **node, listint_t **head)
{
	listint_t *node_t = *node;
	listint_t *prev = node_t->prev;
	listint_t *next = node_t->next;

	if (prev == NULL)
		return (*node);
	node_t->prev = prev->prev;
	if (prev->prev != NULL)
		prev->prev->next = node_t;
	else
		*head = node_t;
	prev->next = next;
	if (next != NULL)
		next->prev = prev;
	node_t->next = prev;
	prev->prev = node_t;
	return (*node);
}

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
