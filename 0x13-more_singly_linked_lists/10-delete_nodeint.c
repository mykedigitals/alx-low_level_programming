#include "lists.h"

/**
 * delete_nodeint_at_index - removes the node at nth path @index of a list
 * @head: two pointer to the beginning of list
 * @index: node to be removed
 *
 * Return: 1 if success, -1 if failure
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *fileTemp;
	listint_t *next;
	unsigned int pointCount = 0;

	fileTemp = *head;
	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = fileTemp->next;
		free(fileTemp);
		return (1);
	}
	while (fileTemp && pointCount < index - 1)
	{
		fileTemp = fileTemp->next;
		pointCount++;
		if (fileTemp == NULL || fileTemp->next == NULL)
			return (-1);
	}
	next = fileTemp->next->next;
	free(fileTemp->next);
	fileTemp->next = next;
	return (1);
}
