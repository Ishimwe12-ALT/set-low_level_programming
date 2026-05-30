#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc_ptrs - reallocates memory for an array of node pointers
 * @list: the old list to append to
 * @size: size of the new list
 * @new_node: new node to add to the array
 *
 * Return: pointer to the new list
 */
const listint_t **_realloc_ptrs(const listint_t **list, size_t size,
				const listint_t *new_node)
{
	const listint_t **new_list;
	size_t i;

	new_list = malloc(size * sizeof(listint_t *));
	if (new_list == NULL)
	{
		free((void *)list);
		exit(98);
	}

	for (i = 0; i < size - 1; i++)
		new_list[i] = list[i];

	new_list[i] = new_node;
	free((void *)list);

	return (new_list);
}

/**
 * print_listint_safe - safely prints a listint_t linked list.
 * @head: pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i, num = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (i = 0; i < num; i++)
		{
			if (head == list[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free((void *)list);
				return (num);
			}
		}
		num++;
		list = _realloc_ptrs(list, num, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}

	free((void *)list);
	return (num);
}
