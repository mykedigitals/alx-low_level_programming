#include "lists.h"

/**
 * sum_listint - this returns the addition of all the elements of a list
 * @head: the first element of the list
 *
 * Return: the addition, 0 if list is empty
 */

int sum_listint(listint_t *head)
{
	int addUp = 0;

	if (head == NULL)
		return (0);

	while (head)
	{
		addUp += head->n;
		head = head->next;
	}
	return (addUp);
}
