#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at a given index
 * @head: pointer to pointer of the head node
 * @index: index of the node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current;
	listint_t *to_delete;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		to_delete = *head;
		*head = (*head)->next;
		free(to_delete);
		return (1);
	}

	current = *head;
	i = 0;

	while (current->next != NULL && i < index - 1)
	{
		current = current->next;
		i++;
	}

	if (current->next == NULL)
		return (-1);

	to_delete = current->next;
	current->next = to_delete->next;
	free(to_delete);

	return (1);
}
