#include "monty.h"

/**
 * short_stack_error - error msg for monty math funcs with < 2 nodes
 *@line_number: line with error0
 * @op: Operation where the error occurred
 * Return: EXIT_FAILURE
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - error msg for division by 0
 * @line_number: Line number where error occurs0
 * Return: EXIT_FAILURE
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pop_error - prints pop error msg for empty stacks
 * @line_number: Line number with error
 * Return: EXIT_FAILURE
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 * @line_number: Line number in Monty
 * @msg: corresponding error message to print
 * Return: EXIT_FAILURE
 */

int pchar_error(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint error msg for empty stacks.
 * @line_number: Line number in Monty
 * Return: EXIT_FAILURE
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
