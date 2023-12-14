#include "monty.h"

/**
 * r_pall - pall the stack
 * @head: stack head
 * @counter: num
 * Return: none
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *tl;
	(void)counter;

	tl = *head;
	if (tl == NULL)
		return;
	while (tl)
	{
		printf("%d\n", tl->n);
		tl = tl->next;
	}
}

/**
 * r_pop - function prints the top
 * @head: stack head
 * @counter: num
 * Return: none
 */
void r_pop(stack_t **head, unsigned int counter)
{
	stack_t *tl;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tl = *head;
	*head = tl->next;
	free(tl);
}

/**
 * r_push - function add node to the stack
 * @head: stack head
 * @counter: num
 * Return: none
 */
void r_push(stack_t **head, unsigned int counter)
{
	int i, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		addno(head, i);
	else
		addqu(head, i);
}


/**
 * addno - function add to the head 
 * @head: head stack
 * @i: num
 */
void addno(stack_t **head, int i)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = i;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * free_stack - frees a doublylist
 * @head: head of the stack
 * Return: none
 */
void free_stack(stack_t *head)
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
