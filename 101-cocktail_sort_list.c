#include "sort.h"

void _swapNode(listint_t **list, listint_t **p);

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
				_swapNode(list, &current);
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
				current = current->prev;
				_swapNode(list, &current);
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}

/**
 * _swapNode - swaps element in a doublyLinkedList (int)
 * @list: head node
 * @p: pointer to node
 */
void _swapNode(listint_t **list, listint_t **p)
{
	listint_t *one, *two, *three, *four;

	one = (*p)->prev;
	two = *p;
	three = (*p)->next;
	four = (*p)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*p = three;
}
