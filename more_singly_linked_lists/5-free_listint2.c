#include "lists.h"
#include <stdlib.h>

/**
 * _realloc_free - reallocates memory for an array of node pointers
 * @list: the old list
 * @size: size of the new list
 * @new_node: new node to add
 *
 * Return: pointer to the new list
 */
listint_t **_realloc_free(listint_t **list, size_t size, listint_t *new_node)
{
	listint_t **new_list;
	size_t i;

	new_list = malloc(size * sizeof(listint_t *));
	if (new_list == NULL)
	{
		free(list);
		exit(98);
	}

	for (i = 0; i < size - 1; i++)
		new_list[i] = list[i];

	new_list[i] = new_node;
	free(list);

	return (new_list);
}

/**
 * free_listint_safe - safely frees a listint_t list.
 * @h: double pointer to the head of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t i, num = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		for (i = 0; i < num; i++)
		{
			if (*h == list[i])
			{
				*h = NULL;
				free(list);
				return (num);
			}
		}
		num++;
		list = _realloc_free(list, num, *h);
		next = (*h)->next;
		free(*h);
		*h = next;
	}

	free(list);
	return (num);
}
