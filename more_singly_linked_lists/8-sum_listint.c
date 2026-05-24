#include "lists.h"

/**
 * sum_listint - returns the sum of all the data
 * @head: pointer to the first node
 *
 * Return: sum of all data or 0 if empty
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
