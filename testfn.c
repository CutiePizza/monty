#include "monty.h"

/**
 * push - push a new num to the stack
 * @st: top of stack
 * @line_number: line number of function
 */

void push(int num, stack_t **st, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!num)
	{
		if (*st != NULL)
			free_list(*st);
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		fclose(glob);
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
	  if (*st != NULL)
			free_list(*st);
		fprintf(stderr, "Error: malloc failed\n");
		fclose(glob);
		exit(EXIT_FAILURE);
	}
	node->n = num;
	if (*st != NULL)
		(*st)->prev = node;
	node->next = (*st);
	node->prev = NULL;
	(*st) = node;
}

/**
 * pall - Display the elements of the stack
 * @st: Top of the stack
 * @line_number: line number
 */

void pall(stack_t **st, unsigned int line_number)
{
	unsigned int i = 0;
	stack_t *p = *st;

	(void)line_number;
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
		i++;
	}
}

/**
 * pint - Display only the top element of the stack
 * @st: Top pf the stack
 * @line_number: line number
 */

void pint(stack_t **st, unsigned int line_number)
{
	stack_t *p = *st;

	if (p && line_number)
		printf("%d\n", p->n);
	else
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 *
 *
 */
void nop(stack_t **st, unsigned int line_number)
{
if (line_number && st)
return;
}
