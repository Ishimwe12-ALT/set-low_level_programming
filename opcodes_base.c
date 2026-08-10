#include "monty.h"

void f_push(stack_t **head, unsigned int counter)
{
int n, j = 0, flag = 0;
stack_t *new_node;

if (bus.arg)
{
if (bus.arg[0] == '-')
j++;
for (; bus.arg[j] != '\0'; j++)
{
if (bus.arg[j] < '0' || bus.arg[j] > '9')
flag = 1;
}
if (flag == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
n = atoi(bus.arg);

new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
new_node->n = n;
new_node->prev = NULL;
new_node->next = *head;
if (*head)
(*head)->prev = new_node;
*head = new_node;
}

void f_pall(stack_t **head, unsigned int counter)
{
stack_t *h = *head;
(void)counter;

while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}

void f_pint(stack_t **head, unsigned int counter)
{
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}

void free_stack(stack_t *head)
{
stack_t *tmp;

while (head)
{
tmp = head->next;
free(head);
head = tmp;
}
}
