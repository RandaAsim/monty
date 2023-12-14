#include "monty.h"
/**
 * r_pint - function prints
 * @head: stack head
 * @co: num
 * Return: none
 */
void r_pint(stack_t **head, unsigned int co)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", co);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * r_pchar - function prints the char
 * @head: stack head
 * @counter: num
 */
void r_pchar(stack_t **head, unsigned int counter)
{
	stack_t *tl;

	tl = *head;
	if (!tl)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (tl->n > 127 || tl->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tl->n);
}
/**
 * addqu - function add node
 * @i: num@head: head stack
 * Return: none
 */
void addqu(stack_t **head, int i)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = i;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
 * r_pstr - function prints the string at the top
 * @head: stack head
 * @counter: num
 */
void r_pstr(stack_t **head, unsigned int counter)
{
	stack_t *tl;
	(void)counter;

	tl = *head;
	while (tl)
	{
		if (tl->n > 127 || tl->n <= 0)
		{
			break;
		}
		printf("%c", tl->n);
		tl = tl->next;
	}
	printf("\n");
}
