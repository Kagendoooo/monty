#include <stdio.h>
#include <stddef.h>
#include "monty.h"
#include <stdlib.h>

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

/**
 * monty_pint - prints the head value of a stack linked list
 * @stack: Pointer to head of stacked linked list
 * @line_number: current line num of monty
 */

void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pop - Remove top value element of linked list
 * @stack: Pointer to top node of linked list
 * @line_number: current working line number of a Monty bytecodes file
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - Swap top two value elements of linked list
 * @stack: Pointer to the top node of linked list
 * @line_number: current working line number of a Monty bytecodes file
*/
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
