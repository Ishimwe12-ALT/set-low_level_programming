#include <stddef.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head of the listint_t linked list.
 * @index: Index of the node, starting at 0.
 *
 * Return: Pointer to the requested node, or NULL if it doesn't exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int current_index = 0;

	while (head != NULL)
	{
		if (current_index == index)
			return (head);

		current_index++;
		head = head->next;
	}

	return (NULL);
}
