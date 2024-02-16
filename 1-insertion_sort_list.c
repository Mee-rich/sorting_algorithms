#include "sort.h"

/**
 * insertion_sort_list - insertion sorting algorithm
 * @list: linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *tmp;
	int swapped;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;
	while (current)
	{
		swapped = 0;
		tmp = current;
		prev = current->prev;

		while (prev && tmp->n < prev->n)
		{
			if (prev->prev)
				prev->prev->next = tmp;
			else
				*list = tmp;
			if (tmp->next)
				tmp->next->prev = prev;
			
			prev->next = tmp->next;
			tmp->prev = prev->prev;

			tmp->next = prev;
			prev->prev = tmp;

			print_list(*list);
			swapped = 1;
			tmp = prev;
			prev = tmp->prev;
		}

		if (!swapped)
			current = current->next;
	}
}
