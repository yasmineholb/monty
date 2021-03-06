#include "monty.h"

/**
 * push - push a new num to the stack
 * @st: top of stack
 * @line_number: line number of function
 * @ch: num to add to stack
 */

void push(char *ch, stack_t **st, unsigned int line_number)
{
	stack_t *node = NULL;

	if (ch == NULL || check_digit(ch) == 1)
	{
		glob = 1;
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		return;
	}
	else
	{
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		glob = 1;
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}
	node->n = atoi(ch);
	if (*st != NULL)
		(*st)->prev = node;
	node->next = (*st);
	node->prev = NULL;
	(*st) = node;
	}
}

/**
 * pall - Display the elements of the stack
 * @st: Top of the stack
 * @line_number: line number
 */

void pall(stack_t **st, unsigned int line_number)
{
	stack_t *p = *st;

	(void)line_number;
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}

/**
 * pint - Display only the top element of the stack
 * @st: Top pf the stack
 * @line_number: line number
 */

void pint(stack_t **st, unsigned int line_number)
{
	stack_t *p = *st;
	(void)line_number;

	if (p)
		printf("%d\n", p->n);
	else
	{
		glob = 1;
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		return;
	}
}

/**
 * nop - Does nothing
 * @st: Top pf the stack
 * @line_number: line number
 */

void nop(stack_t **st, unsigned int line_number)
{
	(void)st;
	(void)line_number;
		return;
}
