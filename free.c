#include "monty.h"

/**
 * free_dlistint - free a list
 * @head: head stack
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
