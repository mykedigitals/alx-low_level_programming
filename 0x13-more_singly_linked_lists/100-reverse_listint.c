#include "lists.h"

/**
 * reverse_listint - this function reverses a specific list
 * @head: this is the beginning of the list to be reversed
 * Return: this is to return the pointer that points to the
 * reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *back = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = back;
		back = *head;
		*head = next;
	}
	*head = back;
	return (*head);
}
