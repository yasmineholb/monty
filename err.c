#include "monty.h"

/**
 * malloc_failed - display error for malloc
 * @mo: file descriptor
 */
void malloc_failed(FILE *mo)
{
	fclose(mo);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);

}
/**
 * print_err - display error
 */
void print_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * cant_open - display error
 * @argv: string
 */
void cant_open(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
