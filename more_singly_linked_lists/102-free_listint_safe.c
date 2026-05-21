#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely (handles loops)
 * @h: pointer to pointer of the head node
 *
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *tmp;
	size_t count;

	slow = *h;
	fast = *h;
	count = 0;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	slow = *h;
	while (slow != NULL)
	{
		tmp = slow->next;
		free(slow);
		count++;
		if (tmp == fast && fast != NULL)
		{
			free(fast);
			count++;
			break;
		}
		slow = tmp;
	}
	*h = NULL;
	return (count);
}
