#include "lists.h"

/**
 * pop_listint - deletes the head node of a list
 * and returns its element
 * @head: the head node of the list
 *
 * Return: data of head node, or 0 if empty
 */

int pop_listint(listint_t **head)
{
	listint_t *tempFree;
	int headNode;

	if (*head == NULL)
		return (0);

	tempFree = *head;
	headNode = tempFree->n;
	*head = tempFree->next;

	free(tempFree);
	return (headNode);
}
