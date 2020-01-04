#include "monty.h"

char *glob = NULL;

/**
 * divide - Interpret the line given
 * @line: string to interpret
 * @line_num: Line number in the file
 * @head: Top of the stack
 */

void divide(char *line, unsigned int line_num, stack_t **head)
{
	char *ch, *cch;
	void (*fn)(stack_t **, unsigned int);

	ch = malloc(sizeof(line));
	cch = malloc(sizeof(line));
	if (ch == NULL || cch == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ch = strtok(line, " \n");
	if (ch == NULL)
		return;
	cch = strtok(0, " \n");
	if (cch != NULL)
		glob = strdup(cch);
	fn = get_fn(ch);
	if (fn == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_num, ch);
		exit(EXIT_FAILURE);
	}
	fn(&(*head), line_num);
}

/**
 * get_fn - get the function associated to the opcode
 * @ch: opcode
 * Return: Pointer to function
 */

void (*get_fn(char *ch))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t tab[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
};

	while (tab[i].opcode != NULL)
	{
		if (strcmp(tab[i].opcode, ch) == 0)
			break;
		i++;
	}
	return (tab[i].f);
}
