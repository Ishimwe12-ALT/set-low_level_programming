#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *node, *check;
	size_t count = 0;

	node = head;

	while (node)
	{
		check = head;

		while (check != node)
		{
			if (check == node->next)
			{
				printf("-> [%p] %d\n",
					(void *)node->next,
					node->next->n);
				return (count);
			}

			check = check->next;
		}

		printf("[%p] %d\n", (void *)node, node->n);
		count++;
		node = node->next;
	}

	return (count);
}
