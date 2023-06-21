#include "monty.h"

/**
 * pstr - prints the string of the stack
 *
 * @head: head of the linked list
 * @nline: line number
 * Return: nothing
 */
void pstr(stack_t **head, unsigned int nline)
{
	stack_t *ptr;
	(void)nline;

	ptr = *head;

	while (ptr && ptr->n > 0 && ptr->n < 128)
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}

	printf("\n");
}

/**
 * pchar - print the char value of the first elemnt
 *
 * @head: head of the linked list
 * @nline: line number
 * Return: nothing
 */
void pchar(stack_t **head, unsigned int nline)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", nline);
		free_glob_v();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", nline);
		free_glob_v();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
/**
 * mod - computes the rest of the division of the second elemnt
 * by the top elemnt of the stack
 *
 * @head: head of the linked list
 * @nline: line number
 * Return: nothing
 */
void mod(stack_t **head, unsigned int nline)
{
	int i = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", nline);
		free_glob_v();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nline);
		free_glob_v();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n %= (*head)->n;
	pop(head, nline);
}
/**
 * mul - multiplies the top element to the second top element of stack.
 *
 * @head: head of the linked list.
 * @nline: line number.
 * Return: nothing.
 */
void mul(stack_t **head, unsigned int nline)
{
	int i = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", nline);
		free_glob_v();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n *= (*head)->n;
	pop(head, nline);

}
/**
 * _div - divides the second element by the top element of the stack
 *
 * @head: head of the linked list
 * @nline: line number.
 * Return: nothing
 */
void _div(stack_t **head, unsigned int nline)
{
	int i = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", nline);
		free_glob_v();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nline);
		free_glob_v();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n /= (*head)->n;
	pop(head, nline);
}
