#include "monty.h"
/**
 * is_intiger - execute function if available
 * @token: Line content in position [1]
 * Return: void
 */
bool is_intiger(char *token)
{
	unsigned int i;

	for (i = 0; token && token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] <= 47 || token[i] >= 58)
			return (false);
	}
	return (true);
}

/**
 * pchar - Aprint de first node as char value
 * @head: pointer to address of list
 * @line_number: line number
 * Return: void
 */
void pchar(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (head && *head)
	{
		temp = *head;
		if(temp->n >= 0 && temp->n <= 127)
			printf("%c\n", temp->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}