#include "monty.h"
/**
 * add_dnodeint - Adds a new node at the start of a stack
 * @head: pointer to address of list
 * @n: integer data
 * Return: address of new head
 */
void push(stack_t **head, unsigned int line_number)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
        exit(EXIT_FAILURE);
    new->n = argument;
    new->next = *head;
    new->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new;
    *head = new;
}
/**
 * pall - Prints the elements of a stack
 * @h: pointer to the head of the stack
 * Return: number of elements in the stack
 */
void pall(stack_t **head, unsigned int line_number)
{
    stack_t *h = *head;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}
