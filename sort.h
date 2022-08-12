#ifndef _SORT_H
#define _SORT_H

/* -- standard libraries -- */
#include <stdio.h>
#include <stdlib.h>

/* -- structures -- */

/**
 * struct listint_s - Double linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* -- function prototypes -- */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void _swap(int *a, int *b);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

#endif /* _SORT_H */
