#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - delete node at index
 * @head: pointer to head
 * @index: index
 *
 * Return: 1 if success, -1 if fail
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = temp->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	if (!temp)
		return (-1);

	if (temp->prev)
		temp->prev->next = temp->next;

	if (temp->next)
		temp->next->prev = temp->prev;

	free(temp);
	return (1);
}
