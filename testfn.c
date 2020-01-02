#include "monty.h"
/**
 *
 *
 */
void push(stack_t **st, unsigned int line_number)
{
stack_t *node = NULL;
if (!isdigit(glob) || glob == NULL)
fprintf(stderr, "L%i: usage: push integer\n", line_number, 25);
node = malloc(sizeof(stack_t));
if node == NULL
{
perror("Error: malloc failed\n");
exit(EXIT_FAILURE);
}
node->n=glob;
if *st != NULL
(*st)->prev=node;
node->next= (*st);
node->prev=NULL;
(*st) = node;
}

void 
