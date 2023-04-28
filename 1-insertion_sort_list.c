#include "sort.h"

/**
 * swap_nodes - swap two nodes in doubly-linked list.
 * @h: pointer to head of doubly-linked list.
 * @n1: pointer to first node in swap.
 * @n2: second node to be swapped.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts doubly linked list of ints
 * which uses the insertion sort algorithm.
 * @list: pointer to head of doubly-linked list of ints.
 *
 * Description: prints list at each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *it, *input, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (it = (*list)->next; it != NULL; it = tmp)
	{
		tmp = it->next;
		input = it->prev;
		while (input != NULL && it->n < input->n)
		{
			swap_nodes(list, &input, it);
			print_list((const listint_t *)*list);
		}
	}
}
