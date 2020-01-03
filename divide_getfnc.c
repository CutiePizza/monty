#include "monty.h"

/**
 * divide - Interpret the line given
 * @line: string to interpret
 * @line_num: Line number in the file
 */

void divide(char *line, int line_num)
{
	char *ch, *cch;
	void (*fn)(stack_t **, unsigned int);
	stack_t *head = NULL;
	
	ch = malloc(sizeof(line));
	cch = malloc(sizeof(line));
	if (ch == NULL || cch == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ch = strtok(line, " \n");
	printf("%s\n", ch);
	cch = strtok(NULL, " \n");
	printf("%s\n", cch);
	glob = strdup(cch);
	/*if (cch != NULL)
	{
		if (isdigit(cch) != 0)
			glob = atoi(cch);
	}*/
	fn = get_fn(ch);
	if (fn == NULL)
	{	//fprintf(stderr, "L%i: unknown instruction %s\n", line_num, ch, 26);
		exit(EXIT_FAILURE);
	}
	fn(&head, line_num);
//	free(ch);
//	free(cch);
}

/**
 * get_fn - get the function associated to the opcode
 * @ch: opcode
 * Return: Pointer to function
 */

void (*get_fn(char *ch))(stack_t **, unsigned int)
{
	int i = 0;

	/* stack_t tab[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	}; */
	instruction_t tab[] = {
		{"push", push},
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
