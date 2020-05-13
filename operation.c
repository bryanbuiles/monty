#include "monty.h"
/**
 * op - execute function if available
 * @line: struct conaining lines
 * @f: file to open
 * @s: head of stack
 * Return: void
 */

void (*op())(stack_t **, unsigned int)
{
	unsigned int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}};
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, montyData.contenido[0]) == 0)
		{	
			free(montyData.contenido);
			return (ops[i].f);
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", montyData.number, montyData.contenido[0]);
	free(montyData.contenido[0]);
	free(montyData.contenido);
	fclose(montyData.file);
	exit(EXIT_FAILURE);
}
