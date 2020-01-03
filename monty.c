#include "monty.h"
/**
 *
 *
 */
int main(int argc, char *argv[])
{
	int re, len = 0, line_num = 0;
	char *line = NULL;
	FILE *mo;
	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mo = fopen(argv[1], "r");
	if (mo == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1], 25);
		exit(EXIT_FAILURE);
	}
	while (re = getline(&line, &len, mo))
	{
		divide(line, line_num);
	}
	return(0);
}
