#include "monty.h"

void f_pchar(stack_t **head, unsigned int counter)
{
stack_t *h = *head;

if (!h)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
if (h->n < 0 || h->n > 127)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%c\n", h->n);
}
