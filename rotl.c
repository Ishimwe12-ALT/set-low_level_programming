#include "monty.h"

void f_rotl(stack_t **head, unsigned int counter)
{
stack_t *tmp = *head, *aux;
(void)counter;

if (*head == NULL || (*head)->next == NULL)
return;

aux = (*head)->next;
aux->prev = NULL;
while (tmp->next != NULL)
tmp = tmp->next;

tmp->next = *head;
(*head)->next = NULL;
(*head)->prev = tmp;
(*head) = aux;
}
