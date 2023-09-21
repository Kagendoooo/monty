#include <stdio.h>
#include "monty.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * usage_error - prints usage error & returns error code
 * Return: EXIT_FAILURE
 */
int usage_error(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 18);
	return (EXIT_FAILURE);
}

/**
 * f_open_error - prints file open error with file name
 * @filename: name of file failed to open
 * Return: EXIT_FAILURE
 */

int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc error info and returns error code
 * Return: EXIT_FAILURE
 */

int malloc_error(void)
{
	write(STDERR_FILENO, "Error: malloc failed\n", 21);
	return (EXIT_FAILURE);
}

/**
 *unknown_op_error - prints error msg for unknown instruction
 *@opcode: opcode where error occurred
 *@line_number: line number with error
 *Return: EXIT_FAILURE
 */

int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - prints error upon upon invalid argument
 * @line_number: line with error
 * Return: EXIT_FAILURE
 */

int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
