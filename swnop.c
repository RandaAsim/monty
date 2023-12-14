#include "monty.h"

/**
 * r_swap - swap top of stack
 * @stack: pointer
 * @line_number: num
 * Return: none
 */

void r_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * r_nop- just function
 * @head: head of stack
 * @counter: line_number
 * Return: none
 */
void r_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
