#include "monty.h"

/**
 * rotr - reverses the stack
 *
 * @head: head of the linked list
 * @nline: line number
 * Return: nothing
 */
void rotr(stack_t **head, unsigned int nline)
{
	stack_t *ptr = NULL;
	(void)nline;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	ptr = *head;

	for (; ptr->next != NULL; ptr = ptr->next)
		;

	ptr->prev->next = NULL;
	ptr->next = *head;
	ptr->prev = NULL;
	(*head)->prev = ptr;
	*head = ptr;
}
/**
 * rotl - rotates the first element to the bottom and the second to the top.
 *
 * @head: head of the linked list
 * @nline: line number
 * Return: nothing
 */
void rotl(stack_t **head, unsigned int nline)
{
	stack_t *ptr1 = NULL;
	stack_t *ptr2 = NULL;
	(void)nline;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	ptr1 = (*head)->next;
	ptr2 = *head;

	for (; ptr2->next != NULL; ptr2 = ptr2->next)
		;

	ptr1->prev = NULL;
	ptr2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = ptr2;
	*head = ptr1;
}
