#include "monty.h"
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
		fprintf(stderr, "Error: malloc failed");
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
/**
 * swap - swaps the top two elements of the stack.
 * @head: Addres of start in list
 * @line_number: Line number
 * Return: void
 */
void swap(stack_t **head, unsigned int line_number)
{
	int temp;

	if (head == NULL || *head == NULL || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*head)->n;
		(*head)->n = (*head)->next->n;
		(*head)->next->n = temp;
	}
}
/**
 * add - add the top two elements of the stack and pop.
 * @head: Addres of start in list
 * @line_number: Line number
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n += (*head)->n;
		pop(head, line_number);
	}
}
