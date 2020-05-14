#include "monty.h"
/**
 * op - execute function if available
 * @l: struct conaining ls
 * @f: file to open
 * @s: head of stack
 * Return: void
 */

void (*op(byteline_t l, FILE * f, stack_t **s))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}};
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, l.contenido[0]) == 0)
		{
			if (strcmp(ops[i].opcode, "push") == 0)
			{
				if (is_intiger(l.contenido[1]) && l.contenido[1])
				{
					argument = atoi(l.contenido[1]);
				}
				else
				{
					free(l.contenido[0]);
					free(l.contenido);
					fclose(f);
					free_stack(s);
					fprintf(stderr, "L%d: usage: push integer\n", l.number);
					exit(EXIT_FAILURE);
				}
			}
			free(l.contenido);
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", l.number, l.contenido[0]);
	free(l.contenido[0]);
	free(l.contenido);
	fclose(f);
	exit(EXIT_FAILURE);
}
