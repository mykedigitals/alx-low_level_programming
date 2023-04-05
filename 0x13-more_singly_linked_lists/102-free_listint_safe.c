#include "lists.h"

/**
 * free_listint_safe - free up linked list from the back
 * @h: this is the pointer to the first node of the element linked list
 *
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)
{
	size_t hare = 0;
	int light;
	listint_t *tmpTemp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		light = *h - (*h)->next;
		if (light > 0)
		{
			tmpTemp = (*h)->next;
			free(*h);
			*h = tmpTemp;
			hare++;
		}
		else
		{
			free(*h);
			*h = NULL;
			hare++;
			break;
		}
	}

	*h = NULL;

	return (hare);
}
