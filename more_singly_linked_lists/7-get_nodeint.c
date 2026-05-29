#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node
 * @head: pointer to head
 * @index: index of node
 *
 * Return: pointer to node or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);

		head = head->next;
		i++;
	}

	return (NULL);
}
