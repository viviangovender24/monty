#include "monty.h"

/**
 * pintv - rpints the value at the top of the stack.
 *
 * @head: head of the linked list.
 * @nline: line number
 * Return: nothing
 */
void pintv(stack_t **head, unsigned int nline)
{
	(void)nline;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", nline);
		dprintf(2, "can't pint, stack empty\n");
		freeglob();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * popv - removes the top element of the stack.
 *
 * @head: head of the linked list.
 * @nline: line number
 * Return: nothing.
 */
void popv(stack_t **head, unsigned int nline)
{
	stack_t *ptr;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", nline);
		freeglob();
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	*head = (*head)->next;
	free(ptr);
}

/**
 * swapv - swaps the top two elements of the stack.
 *
 * @head: head of the linked list.
 * @nline: line number.
 * Return: nothing
 */
void swapv(stack_t **head, unsigned int nline)
{
	int i = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", nline);
		freeglob();
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	*head = (*head)->next;
	ptr->next = (*head)->next;
	ptr->prev = *head;
	(*head)->next = ptr;
	(*head)->prev = NULL;
}

/**
 * pushv - pushes an element to the stack
 *
 * @head: head of the linked list
 * @nline: line number
 * Return: no return.
 */
void pushv(stack_t **head, unsigned int nline)
{
	int n, j;

	if (!glob_v.arg)
	{
		dprintf(2, "L%u: ", nline);
		dprintf(2, "usage: push integer\n");
		freeglob();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glob_v.arg[j] != '\0'; j++)
	{
		if (!isdigit(glob_v.arg[j]) && glob_v.arg[j] != '-')
		{
			dprintf(2, "L%u: ", nline);
			dprintf(2, "usage: push integer\n");
			freeglob();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glob_v.arg);

	if (glob_v.lifo == 1)
		add_int(head, n);
	else
		add_int_end(head, n);
}

/**
 * pallv - prints all values on the stack
 *
 * @head: head of the linked list
 * @nline: line numbers
 * Return: no return
 */
void pallv(stack_t **head, unsigned int nline)
{
	stack_t *aux;
	(void)nline;

	aux = *head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
