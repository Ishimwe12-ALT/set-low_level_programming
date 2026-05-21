#include "lists.h"

/**
 * sum_listint - returns the sum of all data in a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: sum of all nodes, or 0 if list is empty
 */
int sum_listint(listint_t *head)
{
	int sum;
	listint_t *current;

	sum = 0;
	current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
