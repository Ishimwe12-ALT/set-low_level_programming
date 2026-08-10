#include "monty.h"

void f_pstr(stack_t **head, unsigned int counter)
{
stack_t *h = *head;
(void)counter;

while (h)
{
if (h->n <= 0 || h->n > 127)
break;
printf("%c", h->n);
h = h->next;
}
printf("\n");
}
