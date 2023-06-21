#include "monty.h"

/**
 * opcodes_get - Selects the correct opcode to perform
 *
 * @opcode: opcode passed
 *
 * Return: pointer to the function that executes the opcode.
 */
void (*opcodes_get(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t command[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"queue", queue},
		{"stack", stack},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; command[i].opcode; i++)
		if (_strcmp(command[i].opcode, opcode) == 0)
			break;
	return (command[i].f);
}
