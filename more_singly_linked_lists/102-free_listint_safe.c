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

	if (h == NULL || *h == NULL)
	{
		if (h != NULL)
			*h = NULL;
		return (0);
	}

	slow = *h;
	fast = *h;

	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	if (fast->next == NULL || fast->next->next == NULL)
	{
		while (*h != NULL)
		{
			tmp = (*h)->next;
			free(*h);
			count++;
			*h = tmp;
		}
		*h = NULL;
		return (count);
	}

	fast = *h;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	while (*h != slow)
	{
		tmp = (*h)->next;
		free(*h);
		count++;
		*h = tmp;
	}

	slow = slow->next;
	while (slow != *h)
	{
		tmp = slow->next;
		free(slow);
		count++;
		slow = tmp;
	}
	free(*h);
	count++;
	*h = NULL;
	return (count);
}
