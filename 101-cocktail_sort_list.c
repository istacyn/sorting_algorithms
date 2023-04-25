
#include "sort.h"

/**
 * swap_nodes - Swap two nodes in doubly linked list.
 * @list: A double pointer to the head node of the list.
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	temp = node2->next;
	node2->next = node1;
	node1->next = temp;

	temp = node1->prev;
	node1->prev = node2;
	node2->prev = temp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *	in ascending order using the Cocktail shaker sort algorithm.
 * @list: A double pointer to the head node of the
 *		doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (temp = temp->prev; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				print_list(*list);
				swapped = 1;
			}
		}
	}
}
