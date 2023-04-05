#include "lists.h"

/**
 * insert_nodeint_at_index - slot in a new node at a specific position
 * @head: double pointer to head node
 * @idx: nth position of the list where the new node should be inserted
 * @n: the element to enter for the new node
 *
 * Return: location of the new node, NULL if failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *nodeSlot = *head;
	listint_t *newSlot;
	unsigned int numbering = 0;

	if (nodeSlot == NULL && idx != 0)
		return (NULL);

	while (nodeSlot && numbering < idx - 1)
	{
		nodeSlot = nodeSlot->next;
		numbering++;
	}
	newSlot = malloc(sizeof(listint_t));
	if (newSlot != NULL)
	{
		newSlot->n = n;
		if (idx == 0)
		{
			newSlot->next = *head;
			*head = newSlot;
			return (newSlot);
		}
		if (numbering + 1 == idx)
		{
			newSlot->next = nodeSlot->next;
			nodeSlot->next = newSlot;
			return (newSlot);
		}
	}
	return (NULL);
}
