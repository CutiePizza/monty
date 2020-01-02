#include "monty.h"
/**
 *
 *
 */
int main(int argc, char *argv[])
{
int re, len = 0, line_num = 0;
char *line = NULL;
FILE *mo;
if argc != 2
{
perror("USAGE: monty file\n");
exit(EXIT_FAILURE);
}
mo = fopen(argv[1], "r");
if mo == NULL
{
perror("Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (re = getline(&line, &len, mo))
{
divide(line, line_num);
}
return(0);
}
void divide (char *line, int line_num)
{
char *ch, *cch;
void (*f) (stack_t, unsigned int);
stack_t *head = NULL;
ch = malloc(sizeof(line));
if (ch == NULL)
{
perror("Error: malloc failed\n");
exit(EXIT_FAILURE);
}
ch = strtok(ch, " \n");
cch = strtok(NULL, " \n");
if cch != NULL
{
if (isdigit(cch))
glob = atoi(cch)
}
f = get_fn(ch);
if f == NULL
{
perror("L%i: unknown instruction %s", line_num, ch);
exit(EXIT_FAILURE);
}
f(&head, line_num);
free(ch);
free(cch);
}


void (*get_fn(char ch))(stack_t, unsigned int)
{
  int i = 0;
  stack_t tab[] = {
    {"push", push },
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {NULL, NULL}
  };

while (array[i].opcode != NULL)
{
if (strcmp(tab[i].opcode, ch) == 0)
return(tab[i].f);
i++;
}
}
