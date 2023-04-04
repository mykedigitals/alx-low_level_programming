#include "lists.h"

/**
 * free_listint2 - frees up a list and sets the @head to NULL
 * @head: double pointer to head of list
 *
 * Return: nothing
 */

void free_listint2(listint_t **head)
{
	listint_t *tempFree;

	if (head)
	{
		while (*head)
		{
			tempFree = *head;
			*head = tempFree->next;
			free(tempFree);
		}
	}
}
