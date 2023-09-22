#include "monty.h"

/**
 * monty_rotl - rotates the head of a stack_t linked list to the bottom.
 * @stack:  pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *tail;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	head = (*stack)->next;
	tail = (*stack)->next;
	while (tail->next != NULL)
		tail = tail->next;

	head->next->prev = *stack;
	(*stack)->next = head->next;
	tail->next = head;
	head->next = NULL;
	head->prev = tail;

	(void)line_number;
}

/**
 * monty_rotr - Rotates the bottom value of a stack_t linked list to the head
 * @stack:  pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *tail;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	head = (*stack)->next;
	tail = (*stack)->next;
	while (tail->next != NULL)
		tail = tail->next;

	tail->prev->next = NULL;
	(*stack)->next = tail;
	tail->prev = *stack;
	tail->next = head;
	head->prev = tail;

	(void)line_number;
}

/**
 * monty_stack - Convert a queue to a stack.
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Converts a stack to a queue
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
