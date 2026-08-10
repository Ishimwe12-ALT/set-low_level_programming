#include "monty.h"

void f_pop(stack_t **head, unsigned int counter)
{
stack_t *h;

if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
*head = h->next;
if (*head)
(*head)->prev = NULL;
free(h);
}

void f_swap(stack_t **head, unsigned int counter)
{
stack_t *h = *head;
int len = 0, aux;

while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
aux = h->n;
h->n = h->next->n;
h->next->n = aux;
}

void f_add(stack_t **head, unsigned int counter)
{
stack_t *h = *head;
int len = 0, aux;

while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
aux = h->n + h->next->n;
h->next->n = aux;
*head = h->next;
free(h);
}

void f_nop(stack_t **head, unsigned int counter)
{
(void)counter;
(void)head;
}

void f_sub(stack_t **head, unsigned int counter)
{
stack_t *aux = *head;
int nodes = 0, diff;

while (aux)
{
aux = aux->next;
nodes++;
}
if (nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = *head;
diff = aux->next->n - aux->n;
aux->next->n = diff;
*head = aux->next;
free(aux);
}

void f_div(stack_t **head, unsigned int counter)
{
stack_t *h = *head;
int len = 0, aux;

while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = h->next->n / h->n;
h->next->n = aux;
*head = h->next;
free(h);
}

void f_mul(stack_t **head, unsigned int counter)
{
stack_t *h = *head;
int len = 0, aux;

while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
aux = h->next->n * h->n;
h->next->n = aux;
*head = h->next;
free(h);
}

void f_mod(stack_t **head, unsigned int counter)
{
stack_t *h = *head;
int len = 0, aux;

while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = h->next->n % h->n;
h->next->n = aux;
*head = h->next;
free(h);
}
