#include "monty.h"
byteline_t data;

/**
 * main - main function
 * @argc: NUmber of argument in prompt
 * @argv: array of pointers that we type
 * Return: exit succes
 */
int main(int argc, char **argv)
{
	size_t size = 0;
	char *buffer = NULL;
	stack_t *stack = NULL;

	data.number = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data.file = fopen(argv[1], "r");
	if (!data.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, data.file) != -1)
	{
		data.number++;
		split_line(buffer, &data, " '\n'");
		if (data.contenido && data.contenido[0])
			op()(&stack, data.number);
		else
			free(data.contenido);
	}
	fclose(data.file);
	free(buffer);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * split_line - split a line in diferrent tokens
 * @buffer: argument of getline typing in prompt
 * @line: struct contain the line of the file
 * @delimiter: delimititer to strtoken
 * Return: void
 */
void split_line(char *buffer, byteline_t *line, char *delimiter)
{
	size_t buffer_size = 3;
	char *strtoken = NULL;
	int i;

	line->contenido = malloc(sizeof(char *) * buffer_size);
	if (line->contenido == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	strtoken = strtok(buffer, delimiter);
	for (i = 0; strtoken && i < 2; i++)
	{
		line->contenido[i] = strtoken;
		strtoken = strtok(NULL, delimiter);
	}
	line->contenido[i] = NULL;
}
