#include "monty.h"

void f_rotr(stack_t **head, unsigned int counter)
{
stack_t *copy = *head;
(void)counter;

if (*head == NULL || (*head)->next == NULL)
return;

while (copy->next)
copy = copy->next;

copy->next = *head;
copy->prev->next = NULL;
copy->prev = NULL;
(*head)->prev = copy;
(*head) = copy;
}
