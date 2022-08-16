#include "sort.h"

void _swapNode(listint_t **head, listint_t **left, listint_t **right);

/**
 * cocktail_sort_list - sorts a doublyLinkedList (int) in ascending order
 *
 * Description: 'Cocktail shaker sort algorithm' improves on bubble sort by
 * operating in two direction; each pass of cocktail sort moves forward, then
 * backward.
 * @list: pointer to node whose prev is null.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int sorted = 0;

	if (!list || !*list)
		return;
	current = *list;
	while (!sorted)
	{
		sorted = 1;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				sorted = 0;
				_swapNode(list, &current, &current->next);
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (sorted)
			break;
		sorted = 1;
		current = current->prev;
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				sorted = 0;
				_swapNode(list, &current->prev, &current);
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}

/**
 * _swapNode - swaps element in a doublyLinkedList (int)
 * @left: node to the left up for swap
 * @right: node to the right up for swap
 */
void _swapNode(listint_t **head, listint_t **left, listint_t **right)
{
	listint_t *tmp1, *tmp2;

	if (!(*left)->prev && !(*right)->next)
	{
		(*left)->prev = *right;
		(*right)->next = *left;
		(*left)->next = (*right)->prev = NULL;
		*head = *right;
	}
	else if (!(*left)->prev && (*right)->next)
	{
		(*left)->prev = *right;
		(*left)->next = (*right)->next;
		(*right)->next->prev = *left;
		(*right)->next = *left;
		(*right)->prev = NULL;
		*head = *right;
	}
	else if ((*left)->prev && !(*right)->next)
	{
		(*right)->next = *left;
		(*right)->prev = (*left)->prev;
		(*left)->prev->next = *right;
		(*left)->prev = *right;
		(*left)->next = NULL;
	}
	else
	{
		tmp1 = *left;
		tmp2 = *right;
		tmp1->next = (*right)->next;
		tmp2->prev = (*left)->prev;
		tmp2->prev->next = tmp2;
		tmp1->next->prev = tmp1;
		tmp1->prev = tmp2;
		tmp2->next = tmp1;
	}
}
