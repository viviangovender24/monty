#ifndef MONTY
#define MONTY

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @current: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO.
 */
typedef struct globals
{
	int lifo;
	unsigned int current;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t glob_v;

/**opcode instructions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **head, unsigned int nline);
void pop(stack_t **head, unsigned int nline);
void swap(stack_t **head, unsigned int nline);
void nop(stack_t **head, unsigned int nline);
void add(stack_t **head, unsigned int nline);
void sub(stack_t **head, unsigned int nline);
void queue(stack_t **head, unsigned int nline);
void stack(stack_t **head, unsigned int nline);
void _div(stack_t **head, unsigned int nline);
void mul(stack_t **head, unsigned int nline);
void mod(stack_t **head, unsigned int nline);
void pstr(stack_t **head, unsigned int nline);
void pchar(stack_t **head, unsigned int nline);
void rotr(stack_t **head, unsigned int nline);
void rotl(stack_t **head, unsigned int nline);


/**get function*/
void(*opcodes_get(char *opcode))(stack_t **stack, unsigned int line_number);

/**doubly linked list functions*/
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/**str functions */
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
int _strcmp(char *s1, char *s2);

/* main*/
void free_glob_v(void);
#endif
