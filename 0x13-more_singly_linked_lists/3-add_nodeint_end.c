#include "lists.h"

/**
 * add_nodeint_end - adds newNode towards ending of a listint_t
 * @head: the implies the beginning of the listint_t
 * @n: this implies the element to be added at the end
 *
 * Return: the address of th new element, NULL if failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newNode;
	listint_t *lastNode;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	else
	{
		lastNode = *head;
		while (lastNode->next)
			lastNode = lastNode->next;
		lastNode->next = newNode;

	}
	return (newNode);
}
