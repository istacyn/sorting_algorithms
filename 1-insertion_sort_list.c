#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked
 *			list of integers in ascending order.
 * @list: The pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next, *temp;
        current = (*list)->next;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		prev = current->prev;
		next = current->next;
		temp = current;
		while (prev != NULL && temp->n < prev->n)
		{
			prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = prev;
			temp->next = prev;
			temp->prev = prev->prev;
			prev->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			prev = temp->prev;
			print_list(*list);
		}
		current = next;
	}
}
