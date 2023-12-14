#include "monty.h"
/**
 * r_swap - function adds two elements of the stack
 * @head: stack head
 * @counter: num
 * Return: none
 */
void r_swap(stack_t **head, unsigned int counter)
{
	stack_t *tl;
	int l = 0, aux;

	tl = *head;
	while (tl)
	{
		tl = tl->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tl = *head;
	aux = tl->n;
	tl->n = tl->next->n;
	tl->next->n = aux;
}

/**
 * r_queue - funtion prints the top
 * @head: stack head
 * @counter: num
 * Return: not return
 */
void r_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * r_stack - function prints the top of stack
 * @head: stack head
 * @counter: num
 * Return: NULl
 */
void r_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
