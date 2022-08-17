#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}

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
