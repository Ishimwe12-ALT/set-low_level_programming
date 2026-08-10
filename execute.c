#include "monty.h"

/**
 * execute - executes opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * Return: 0 on success
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opcodes[] = {
{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
{"nop", f_nop}, {"sub", f_sub}, {"div", f_div},
{"mul", f_mul}, {"mod", f_mod}, {"pchar", f_pchar},
{"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr},
{"stack", f_stack}, {"queue", f_queue}, {NULL, NULL}
};
unsigned int i = 0;
char *op;

op = strtok(content, " \n\t");
if (!op || op[0] == '#')
return (0);

bus.arg = strtok(NULL, " \n\t");
while (opcodes[i].opcode && op)
{
if (strcmp(op, opcodes[i].opcode) == 0)
{
opcodes[i].f(stack, counter);
return (0);
}
i++;
}
if (op && opcodes[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
return (1);
}
