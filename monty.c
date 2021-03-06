#include "monty.h"

int glob = 0;

/**
 * main - main function of Monty's project
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	ssize_t re = 0;
	unsigned int line_num = 1;
	size_t len = 0;
	char *line = NULL, *opcode;
	FILE *mo;
	stack_t *head = NULL;

	if (argc != 2)
		print_err();
	mo = fopen(argv[1], "r");
	if (mo == NULL)
		cant_open(argv[1]);
	opcode = malloc(100);
	if (opcode == NULL)
		malloc_failed(mo);
	while ((re != EOF))
	{
		re = getline(&line, &len, mo);
		if (re == -1)
			break;
		divide(line, line_num, &head, &opcode);
		line_num++;
		if (glob == 1)
		{
			free(line);
			free_list(head);
			fclose(mo);
			free(opcode);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	free_list(head);
	fclose(mo);
	free(opcode);
	exit(EXIT_SUCCESS);
}
