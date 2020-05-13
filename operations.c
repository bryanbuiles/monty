#include "monty.h"

long int argument = 0;
/**
 * add_dnodeint - Adds a new node at the start of a stack
 * @head: pointer to address of list
 * @n: integer data
 * Return: address of new head
 */

void push(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(head);
        exit(EXIT_FAILURE);
    }
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
 * free_dlistint - frees a dlistint_t list
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
