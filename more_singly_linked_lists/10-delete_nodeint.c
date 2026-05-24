#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at index
 * @head: pointer to pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 if success, -1 if failure
 */
int delete_nodeint_at_index(listint_t **head,
	unsigned int index)
{
	listint_t *temp;
	listint_t *current;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	while (temp && i < index - 1)
	{
		temp = temp->next;
		i++;
	}

	if (!temp || !temp->next)
		return (-1);

	current = temp->next;
	temp->next = current->next;

	free(current);

	return (1);
}
