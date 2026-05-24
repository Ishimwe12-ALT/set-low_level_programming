#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t list safely
 * @head: pointer to first node
 *
 * Return: number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);

		if (head <= head->next)
		{
			printf("-> [%p] %d\n",
				(void *)head->next, head->next->n);
			break;
		}

		head = head->next;
		count++;
	}

	return (count);
}
