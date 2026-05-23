#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: pointer to head pointer
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t **visited;
    size_t count = 0, i;
    listint_t *temp;

    if (!h || !*h)
        return (0);

    visited = malloc(sizeof(listint_t *) * 1024);
    if (!visited)
        exit(98);

    while (*h)
    {
        for (i = 0; i < count; i++)
        {
            if (*h == visited[i])
            {
                *h = NULL;
                free(visited);
                return (count);
            }
        }

        visited[count++] = *h;
        temp = (*h)->next;
        free(*h);
        *h = temp;
    }

    free(visited);
    return (count);
}
