#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - to safely loop through a linked list
 * @head: this points to the beginning of the node
 *
 * Return: this returns entirely a new node
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *safeN = NULL;
	const listint_t *nodde = NULL;
	size_t countNumber = 0;
	size_t nodeNew;

	safeN = head;
	while (safeN)
	{
		printf("[%p] %d\n", (void *)safeN, safeN->n);
		countNumber++;
		safeN = safeN->next;
		nodde = head;
		nodeNew = 0;
		while (nodeNew < countNumber)
		{
			if (safeN == nodde)
			{
				printf("-> [%p] %d\n", (void *)safeN, safeN->n);
				return (countNumber);
			}
			nodde = nodde->next;
			nodeNew++;
		}
		if (!head)
			exit(98);
	}
	return (countNumber);
}
