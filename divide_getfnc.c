#include "monty.h"

/**
 * divide - Interpret the line given
 * @line: string to interpret
 * @line_num: Line number in the file
 * @head: Top of the stack
 */

void divide(char *line, unsigned int line_num, stack_t **head)
{
	int ok = 0;
	char *ch, *opcode;
	void (*fn)(stack_t **, unsigned int);

	if (line != NULL)
		ch = malloc(sizeof(line));
	if (ch == NULL)
	{
		if (*head != NULL)
			free_list(*head);
		fclose(glob);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ch = strtok(line, " \n");
	if (ch == NULL)
		return;
	opcode = strdup(ch);
	ch = strtok(0, " \n");
	ok = push_verify(opcode);
	if (ok == 0 && ch != NULL)
		push(ch, &(*head), line_num);
	else
	{
		fn = get_fn(opcode);
		if (fn == NULL)
		{
			if (*head != NULL)
				free_list(*head);
			fclose(glob);
			fprintf(stderr, "L%i: unknown instruction %s\n", line_num, opcode);
			exit(EXIT_FAILURE);
		}
		opcode = NULL;
		free(opcode);
		ch = NULL;
		free(ch);
		fn(&(*head), line_num);
	}
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
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
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
/**
 * free_list - frees a list
 * @head: header of the list
 */

void free_list(stack_t *head)
{
	stack_t *p = NULL;

	while (head != NULL)
	{
		p = head->next;
		free(head);
		head = p;
	}
}

/**
 * push_verify - verify if given char is equal to "push"
 * @ch: string
 * Return: 0 success, -1 failure
 */

int push_verify(char *ch)
{
	if (strcmp("push", ch) == 0)
		return (0);

	return (1);

}

/**
 * check_digit - verify if given char is a digit
 * @cch: string
 * Return: 0 success, -1 failure
 */

int check_digit(char *cch)
{
	unsigned int i;
	int  ok = 0;

	if (cch[0] == '-')
	{
		for (i = 1; i < strlen(cch); i++)
		{
			if (isdigit(cch[i]) == 0)
			{
				ok = 1;
				break;
			}
		}
	}
	else
	{
		for (i = 0; i < strlen(cch); i++)
		{
			if (isdigit(cch[i]) == 0)
			{
				ok = 1;
				break;
			}
		}
	}


	if (ok == 0)
		return (0);
	else
		return (1);
}
