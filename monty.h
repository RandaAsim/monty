#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: num
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: argument value 
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void addqu(stack_t **head, int i);
void r_queue(stack_t **head, unsigned int counter);
void r_stack(stack_t **head, unsigned int counter);
void r_swap(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void r_pall(stack_t **head, unsigned int counter);
void r_pop(stack_t **head, unsigned int counter);
void r_push(stack_t **head, unsigned int counter);
void addno(stack_t **head, int i);
void free_stack(stack_t *head);
void r_pint(stack_t **head, unsigned int co);
void r_pchar(stack_t **head, unsigned int counter);
void r_pstr(stack_t **head, unsigned int counter);
void r_nop(stack_t **head, unsigned int counter);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
#endif/*MONTY.H*/
