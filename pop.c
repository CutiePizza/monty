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

/**
 *
 *
 */
void add(stack_t **st, unsigned int line_number)
{

  unsigned int i = 0, sum=0;
	stack_t *p = *st;

	(void)line_number;
	while (p != NULL)
	{
  
		p = p->next;
		i++;
	}
       
	  if (i < 2)
		  {
	fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
		  }
		else
		  {
		    
		    sum +=(*st)->n;
		    pop(&(*st), line_number);
		    sum += (*st)->n; 
		    (*st)->n = sum;
		  }
	    
}
/**
 *
 *
 */
void sub(stack_t **st, unsigned int line_number)
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
	fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
		  }
		else
		  {
		    
		    sum +=(*st)->n;
		    pop(&(*st), line_number);
		    summ += (*st)->n;
		    res = summ - sum;
		    (*st)->n = res;
		  }
	    
}
/**
 *
 *
 */
void divfn(stack_t **st, unsigned int line_number)
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
	fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
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
		    res = summ / sum;
		    (*st)->n = res;
		      }
		  }
	    
}
