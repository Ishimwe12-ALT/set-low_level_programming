#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node
 * @head: pointer to head pointer
 *
 * Return: head node data or 0
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	n = temp->n;

	*head = temp->next;
	free(temp);

	return (n);
}
