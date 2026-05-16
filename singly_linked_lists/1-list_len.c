#include "lists.h"

/**
 * list_len - returns number of elements
 * @h: pointer to list
 *
 * Return: number of nodes
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
