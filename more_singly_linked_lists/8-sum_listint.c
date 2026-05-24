#include "lists.h"

/**
 * sum_listint - returns the sum of all the data of a listint_t list
 * @head: pointer to the first node
 *
 * Return: sum of all the data, or 0 if the list is empty
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
