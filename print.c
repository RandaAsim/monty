#include "monty.h"

/**
 * r_pint - print int a top of stack
 * @stack: pointer
 * @line_number: number
 * Return: none
 */
void r_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * f_stack - frees a doubly linkedlist
 * @head: head stack
 */
void f_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
