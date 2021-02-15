#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if list is cyclical
 * @list: pointer to list to check
 * Return: 1 if cyclical, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	/*
	listint_t *slow = list, *fast = list;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	*/
	listint_t *check;
	listint_t *current;

	if (list == NULL || list->next == NULL)
		return (0);

	if (list->next == list)
		return (1);

	check = list->next;
	while (check != NULL)
	{
		current = list;
		while (current != check)
		{
			if (current == check->next)
				return (1);
			current = current->next;
		}
		check = check->next;
	}
	
	return (0);
}
