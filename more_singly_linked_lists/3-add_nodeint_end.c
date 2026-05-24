#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end
 * @head: pointer to pointer to first node
 * @n: integer to store
 *
 * Return: address of new element or NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *temp;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	temp = *head;

	while (temp->next)
		temp = temp->next;

	temp->next = new;

	return (new);
}
