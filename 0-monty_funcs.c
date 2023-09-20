#include "monty.h"
/**
 * monty_push - Push value to a stack_t linked list
 * @stack: Pointer to first node of a stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
*/
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *latest;
	int x;

	latest = malloc(sizeof(stack_t));
	if (latest == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (x = 0; op_toks[1][x]; x++)
	{
		if (op_toks[1][x] == '-' && x == 0)
			continue;
		if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	latest->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		temp = (*stack)->next;
		latest->prev = *stack;
		latest->next = temp;
		if (temp)
			temp->prev = latest;
		(*stack)->next = latest;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		latest->prev = temp;
		latest->next = NULL;
		temp->next = latest;
	}
}

/**
 * monty_pall - Prints the values of a stack_t
 * @stack: Pointer to first node of a stack_t
 * @line_number: current working line number of a Monty bytecodes file
*/
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}
