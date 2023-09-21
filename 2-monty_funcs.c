#include "monty.h"
/**
 * monty_nop - Does absolutely nothing for 'nop' opcode
 * @stack: Pointer to top node to linked list.
 * @line_number: current working line number
*/
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
