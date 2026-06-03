#include "lists.h"

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *tmp;
	unsigned int i = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	tmp = *h;

	while (tmp && i < idx - 1)
	{
		tmp = tmp->next;
		i++;
	}

	if (!tmp)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = tmp->next;
	new->prev = tmp;

	if (tmp->next)
		tmp->next->prev = new;

	tmp->next = new;

	return (new);
}
