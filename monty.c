#include "monty.h"
int argument;
/**
 * main - main function
 * @argc: NUmber of argument in prompt
 * @argv: array of pointers that we type
 * Return: exit succes
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t size = 0;
	char *buffer = NULL;
	byteline_t line;
	stack_t *stack = NULL;

	line.number = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, file) != -1)
	{
		line.number++;
		split_line(buffer, &line, " '\n'");
		if (line.contenido && line.contenido[0])
		{
			op(line, file, &stack)(&stack, line.number);
		}
		else
			free(line.contenido);
	}
	fclose(file);
	free(buffer);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
