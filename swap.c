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

/**
*
*
*/
void mul(stack_t **st, unsigned int line_number)
{

  unsigned int i = 0, sum=0, summ = 0, res = 0;
	stack_t *p = *st;

	(void)line_number;
	while (p != NULL)
	{
  
		p = p->next;
		i++;
	}
       
	  if (i < 2)
		  {
	fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
		  }
		else
		  {
		    
		    sum +=(*st)->n;
		    pop(&(*st), line_number);
		    summ += (*st)->n;
		    res = summ * sum;
		    (*st)->n = res;
		  }
	    
}
/**
 *
 *
 */
void modfn(stack_t **st, unsigned int line_number)
{

  unsigned int i = 0, sum=0, summ = 0, res = 0;
	stack_t *p = *st;

	(void)line_number;
	while (p != NULL)
	{
  
		p = p->next;
		i++;
	}
       
	  if (i < 2)
		  {
	fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
	exit(EXIT_FAILURE);
		  }
		else
		  {
		    
		    sum +=(*st)->n;
		    if (sum == 0)
		      {
				fprintf(stderr, "L%i: division by zero\n", line_number);
	exit(EXIT_FAILURE);
		      }
		    else
		      {
		    pop(&(*st), line_number);
		    summ += (*st)->n;
		    res = summ % sum;
		    (*st)->n = res;
		      }
		  }
	    
}
