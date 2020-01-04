#include "monty.h"

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
	char *line = NULL;
	FILE *mo;
	stack_t *head = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mo = fopen(argv[1], "r");
	if (mo == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((re != EOF))
	{
		re = getline(&line, &len, mo);
		if (re == -1)
			break;
		divide(line, line_num, &head);
		line_num++;
	}
	free(line);
	free(head);
	fclose(mo);
	return (EXIT_SUCCESS);
}
