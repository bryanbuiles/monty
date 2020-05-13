#include "monty.h"
/**
 * push - Adds a new node at the start of a stack
 * @head: pointer to address of list
 * @line_number: unused
 * Return: address of new head
 */
void push(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new;
	int argument = 0;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if (is_intiger(data.contenido[1]) && data.contenido[1])
	{
		argument = atoi(data.contenido[1]);
		new->n = argument;
		new->next = *head;
		new->prev = NULL;
		if ((*head) != NULL)
			(*head)->prev = new;
		*head = new;
	}
	else
	{
		free(data.contenido[0]);
		free(data.contenido);
		fclose(data.file);
		free_stack(head);
		fprintf(stderr, "L%d: usage: push integer\n", data.number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pall - Prints the elements of a stack
 * @head: pointer to the head of the stack
 * @line_number: unused
 * Return: number of elements in the stack
 */
void pall(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	temp = *head;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - Aprint de first node
 * @head: pointer to address of list
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp = *head;
	if (temp)
	{
		printf("%d\n", temp->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(data.file);
		free(data.contenido[0]);
		exit(EXIT_FAILURE);
	}
}
/**
 * free_stack - frees a dlistint_t list
 * @head: Addres of start in list
 * Return: void
 */
void free_stack(stack_t **head)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}
