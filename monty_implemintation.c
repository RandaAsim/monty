#include "monty.h"

/**
 * r_nop- yok fuda
 * @head: stack head
 * @counter: num
 */
void r_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 * implement - function executes the opcode
 * @stack: head linked list
 * @counter: integer
 * @file: poiner to monty
 * @content: text
 * Return: none
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", r_push}, {"pall", r_pall}, {"pint", r_pint},
		{"pop", r_pop},
		{"swap", r_swap},
		{"nop", r_nop},
		{"pchar", r_pchar},
		{"pstr", r_pstr},
		{"queue", r_queue},
		{"stack", r_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
