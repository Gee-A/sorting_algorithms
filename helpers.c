#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * backward_swap - swap a node in a list with the previous node
 * provided that the previous node is not null
 * node: the node to swap
 * head: head of the list
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
