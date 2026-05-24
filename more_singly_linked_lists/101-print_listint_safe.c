#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current;
	const listint_t *check;

	current = head;

	while (current)
	{
		check = head;

		while (check != current)
		{
			if (check == current->next)
			{
				printf("-> [%p] %d\n",
					(void *)current->next,
					current->next->n);
				return (count);
			}

			check = check->next;
		}

		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;
	}

	return (count);
}
