#include "monty.h"

/**
 * sub - subtract the top element to the second top element of the stack.
 *
 * @head: head of the linked list.
 * @nline: line number;
 * Return: nothing.
 */
void sub(stack_t **head, unsigned int nline)
{
	int i = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", nline);
		free_glob_v();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n -= (*head)->n;
	pop(head, nline);
}

/**
 * queue - sets the format of the data to a queue
 *
 * @head: head of the linked list.
 * @nline: line number.
 * Return: nothing.
 */
void queue(stack_t **head, unsigned int nline)
{
	(void)head;
	(void)nline;

	glob_v.lifo = 0;
}

/**
 * stack - sets the format of the data to a stack.
 *
 * @head: head of the linked list.
 * @nline: line number.
 * Return: npthing.
 */
void stack(stack_t **head, unsigned int nline)
{
	(void)head;
	(void)nline;

	glob_v.lifo = 1;
}
/**
 * add - adds the top two elements of the stack.
 *
 * @head: head of the linked list
 * @nline: line number
 * Return: nothing
 */
void add(stack_t **head, unsigned int nline)
{
	int i = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", nline);
		free_glob_v();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n += (*head)->n;
	pop(head, nline);
}


/**
 * nop - doesn't do anything
 *
 * @head: head of the linked list.
 * @nline: line number
 * Return: nothing.
 */
void nop(stack_t **head, unsigned int nline)
{
	(void)head;
	(void)nline;
}
