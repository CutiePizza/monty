#include "monty.h"



/**
 * divide - Interpret the line given
 * @line: string to interpret
 * @line_num: Line number in the file
 * @head: Top of the stack
 */

void divide(char *line, unsigned int line_num, stack_t **head)
{       int ok = 0, num = 0;
	char *ch, *cch;
	void (*fn)(stack_t **, unsigned int);
	if (line != NULL)
	{
	ch = malloc(sizeof(line));
	cch = malloc(sizeof(line));
	}
	if (ch == NULL || cch == NULL)
	{
		if (*head != NULL)
			free_list(*head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ch = strtok(line, " \n");
	if (ch == NULL)
		return;
	cch = strtok(0, " \n");
	if (cch != NULL && check_digit(cch) == 0)
	  num = atoi(cch);
	ok = push_verify(ch);
	if (ok == 0)
		   push(num, &(*head), line_num);
	else
	  {
	fn = get_fn(ch);
	if (fn == NULL)
	{
		if (*head != NULL)
			free_list(*head);
		fprintf(stderr, "L%i: unknown instruction %s\n", line_num, ch);
		exit(EXIT_FAILURE);
	}
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
 *
 *
 *
 */
int push_verify(char *ch)
{
  if (strcmp("push", ch) == 0)
	     return(0);
  
  return(1);
  
}
/**
 *
 *
 */
int check_digit(char *cch)
{
  unsigned int i;
  for (i= 0 ; i < strlen(cch); i++)
    {
      if (cch[i] < '0' || cch[i] > '9')
	  return(1);
    }
  return(0);
	  }
