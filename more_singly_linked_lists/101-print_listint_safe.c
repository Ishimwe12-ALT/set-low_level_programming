#include "lists.h"
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t list safely
 * @head: pointer to head
 * Return: number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t **visited;
    size_t count = 0, i;

    visited = malloc(sizeof(listint_t *) * 1024);
    if (!visited)
        exit(98);

    while (head)
    {
        for (i = 0; i < count; i++)
        {
            if (head == visited[i])
            {
                printf("-> [%p] %d\n", (void *)head, head->n);
                free(visited);
                return (count);
            }
        }

        printf("[%p] %d\n", (void *)head, head->n);
        visited[count++] = head;
        head = head->next;
    }

    free(visited);
    return (count);
}
