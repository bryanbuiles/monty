#include "monty.h"
/**
 * op - execute function if available
 * @line: struct conaining lines
 * @f: file to open
 * @s: head of stack
 * Return: void
 */

void (*op(byteline_t line, FILE *f, stack_t **s))(stack_t **, unsigned int)
{
	unsigned int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}};
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, line.contenido[0]) == 0)
		{
			if (strcmp(ops[i].opcode, "push") == 0)
			{
				if (is_intiger(line.contenido[1]) && line.contenido[1])
				{
					argument = atoi(line.contenido[1]);
				}
				else
				{
					free(line.contenido[0]);
					free(line.contenido);
					fclose(f);
					free_stack(s);
					fprintf(stderr, "L%d: usage: push integer\n", line.number);
					exit(EXIT_FAILURE);
				}
			}
			free(line.contenido);
			return (ops[i].f);
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line.number, line.contenido[0]);
	free(line.contenido[0]);
	free(line.contenido);
	fclose(f);
	exit(EXIT_FAILURE);
}
