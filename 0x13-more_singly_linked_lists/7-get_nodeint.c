#include "lists.h"

/**
 * get_nodeint_at_index - this returns the node
 * at a certain index in a linked list
 *
 * @head: the beginning of the node in the linked list
 * @index: numbered position of the node to return
 *
 * Return: pointer to the node we're looking for, or NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *nodeIndex = head;

	while (nodeIndex && i < index)
	{
		nodeIndex = nodeIndex->next;
		i++;
	}

	return (nodeIndex ? nodeIndex : NULL);
}
