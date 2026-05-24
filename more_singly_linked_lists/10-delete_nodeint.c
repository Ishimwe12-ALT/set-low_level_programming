#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at given index
 * @head: pointer to pointer of first node
 * @index: index of node to delete
 *
 * Return: 1 if success, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp;
	listint_t *current;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	while (temp != NULL && i < index - 1)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL || temp->next == NULL)
		return (-1);

	current = temp->next;
	temp->next = current->next;

	free(current);

	return (1);
}
