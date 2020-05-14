#include "monty.h"
/**
 * div - div the top two elements of the stack and pop.
 * @head: Addres of start in list
 * @line_number: Line number
 * Return: void
 */
void div(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n /= (*head)->n;
		pop(head, line_number);
	}
}
/**
 * mul - mul the top two elements of the stack and pop.
 * @head: Addres of start in list
 * @line_number: Line number
 * Return: void
 */
void mul(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n *= (*head)->n;
		pop(head, line_number);
	}
}
/**
 * mod - mod the top two elements of the stack and pop.
 * @head: Addres of start in list
 * @line_number: Line number
 * Return: void
 */
void mod(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n %= (*head)->n;
		pop(head, line_number);
	}
}
