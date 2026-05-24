#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a node at index
 * @head: pointer to pointer to first node
 * @idx: index to insert at
 * @n: value of new node
 *
 * Return: address of new node or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head,
	unsigned int idx, int n)
{
	listint_t *new;
	listint_t *temp;
	unsigned int i = 0;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	temp = *head;

	while (temp && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	if (!temp)
	{
		free(new);
		return (NULL);
	}

	new->next = temp->next;
	temp->next = new;

	return (new);
}
