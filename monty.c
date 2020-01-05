#include "monty.h"

FILE *glob = NULL;

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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mo = fopen(argv[1], "r");
	if (mo == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	glob = mo;
	while ((re != EOF))
	{
		re = getline(&line, &len, mo);
		if (re == -1)
			break;
		divide(line, line_num, &head);
		line_num++;
	}
	free(line);
	free_list(head);
	fclose(mo);
	exit(EXIT_SUCCESS);
}
