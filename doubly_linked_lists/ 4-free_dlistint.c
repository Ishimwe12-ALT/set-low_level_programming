#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - frees list
 * @head: head
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
