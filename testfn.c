#include "monty.h"

/**
 * push - push a new num to the stack
 * @st: top of stack
 * @line_number: line number of function
 */

void push(stack_t **st, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!isdigit(glob) || !glob)
/* fprintf(stderr, "L%i: usage: push integer\n", line_number, 25); */
		printf("%d", line_number);
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
