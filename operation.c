#include "monty.h"
/**
 * op - execute function if available
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
		if (strcmp(ops[i].opcode, data.contenido[0]) == 0)
		{
			free(data.contenido);
			return (ops[i].f);
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", data.number, data.contenido[0]);
	free(data.contenido[0]);
	free(data.contenido);
	fclose(data.file);
	exit(EXIT_FAILURE);
}
