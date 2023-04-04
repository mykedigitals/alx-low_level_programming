#include "lists.h"

/**
 * free_listint - Free up a list
 * @head: the beginning of the list to be freed
 *
 * Return: nothing
 */

void free_listint(listint_t *head)
{
	listint_t *tempFree;

	while (head)
	{
		tempFree = head->next;
		free(head);
		head = tempFree;
	}
}
