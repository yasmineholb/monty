#ifndef monty_h
#define monty_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <error.h>
#include <ctype.h>

extern int glob;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void divide(char *, unsigned int, stack_t **, char **);
void (*get_fn(char *ch))(stack_t **, unsigned int);
void push(char *, stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void free_list(stack_t *head);
void pop(stack_t **st, unsigned int line_number);
void swap(stack_t **st, unsigned int line_number);
void add(stack_t **st, unsigned int line_number);
void sub(stack_t **st, unsigned int line_number);
void divfn(stack_t **st, unsigned int line_number);
void mul(stack_t **st, unsigned int line_number);
void modfn(stack_t **st, unsigned int line_number);
int push_verify(char *);
int check_digit(char *);
void malloc_failed(FILE *);
void print_err(void);
void cant_open(char *argv);
#endif
