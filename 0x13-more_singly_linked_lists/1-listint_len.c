#include "lists.h"

/**
 * listint_len - Brings back the number of elements in a list
 * @h: look in list
 *
 * Return: the list numbers
 */

size_t listint_len(const listint_t *h)
{
	size_t countNumber = 0;

	while (h)
	{
		countNumber++;
		h = h->next;
	}
	return (countNumber);
}
