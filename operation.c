#include "monty.h"
/**
 * get_op_func - execute function if available
 * @line: struct conaining lines
 * @file: file to open
 * Return: void
 */

void (*get_op_func(byteline_t line, FILE *file, stack_t **stack))(stack_t **, unsigned int)
{
	unsigned int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
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
					fclose(file);
					free_stack(stack);
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
	fclose(file);
	exit(EXIT_FAILURE);
}
