#include "monty.h"

global_t glob_v;

/**
 * free_glob_v - fress the global variables.
 */
void free_glob_v(void)
{
	free_dlistint(glob_v.head);
	free(glob_v.buffer);
	fclose(glob_v.fd);
}

/**
 * start_glob_v - initializes the global variables.
 *
 * @fd: file descriptor
 * Return: no return.
 */
void start_glob_v(FILE *fd)
{
	glob_v.lifo = 1;
	glob_v.current = 1;
	glob_v.arg = NULL;
	glob_v.head = NULL;
	glob_v.fd = fd;
	glob_v.buffer = NULL;
}

/**
 * checkinput - checks if the file exist and if the file can be opened.
 *
 * @argc: argument count
 * @argv: argument vector.
 *
 * Return: file struct.
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_glob_v(fd);
	nlines = getline(&glob_v.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(glob_v.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = opcodes_get(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glob_v.current);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_glob_v();
				exit(EXIT_FAILURE);
			}
			glob_v.arg = _strtoky(NULL, "\t\n");
			f(&glob_v.head, glob_v.current);
		}
		nlines = getline(&glob_v.buffer, &size, fd);
		glob_v.current++;
	}

	free_glob_v();

	return (0);
}
