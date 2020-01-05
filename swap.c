#include "monty.h"

/**
 * add_dnodeint - add a node at the beginning of a list
 * @head: head of list
 * @n: integer to add
 * Return: address of the new element
 */

void add_node(stack_t **head, const int n)
{

        stack_t *new = malloc(sizeof(stack_t));

        if (new != NULL)
        {
                new->n = n;
                if (*head != NULL)
                        (*head)->prev = new;
                new->next = (*head);
                new->prev = NULL;
                (*head) = new;
        }
}

/**
 * swap- swap the first two elements of the stack
 * @st: top of stack
 * @line_number: line number of function
 */

void swap(stack_t **st, unsigned int line_number)
{
        stack_t *p = *st;
        int i = 0;
        int num1, num2;

        while (p)
        {
                i++;
                p = p->next;
        }
        if (i < 2)
        {
                glob = 1;
                fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
                return;
        }
num1 = (*st)->n;
pop(&(*st), line_number);
num2 = (*st)->n;
pop(&(*st), line_number);
add_node(&(*st), num1);
add_node(&(*st), num2);
}
