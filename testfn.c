#include "monty.h"

/**
 * push - push a new num to the stack
 * @st: top of stack
 * @line_number: line number of function
 */

void push(stack_t **st, unsigned int line_number)
{
	stack_t *node = NULL;

	if (glob == NULL || !atoi(glob))
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(glob);
	if (*st != NULL)
		(*st)->prev = node;
	node->next = (*st);
	node->prev = NULL;
	(*st) = node;
}

void pall(stack_t **st, unsigned int line_number)
{
	unsigned int i = 0;
	stack_t *p = *st;

	(void)line_number;
	while (p != NULL)
	{
		printf("%d\n", p -> n);
		p = p->next;
		i++;
	}
}

void pint(stack_t **st, unsigned int line_number)
{
	(void)line_number; 
	stack_t *p = *st;
	if (p)
		printf("%d\n", p -> n);
}
