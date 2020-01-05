#include "monty.h"

/**
 * pop - delete first element of the stack
 * @st: top of stack
 * @line_number: line number of function
 */

void pop(stack_t **st, unsigned int line_number)
{
        stack_t *p = NULL;

        if (*st == NULL)
        {
                fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }
        if ((*st) != NULL)
        {
                p = (*st)->next;
                free(*st);
                *st = p;
        }


}