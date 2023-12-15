#include "monty.h"

/**
 * op_rotl - Rotate the stack to the top (left)
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *first, *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = (*stack)->next;
	last = first;

	while (last->next != NULL)
		last = last->next;

	(*stack)->next = first->next;
	first->next->prev = *stack;
	last->next = first;
	first->next = NULL;
	first->prev = last;
}



/**
 * op_rotr - Rotate the stack to the top (right)
 * @stack: stack
 * @line_number: line number
 */
void op_rotr(stack_t **stack
, __attribute__((unused)) unsigned int line_number)
{
	stack_t *last, *secondLast;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	secondLast = NULL;

	/* Traverse the stack to find the last two nodes */
	while (last->next != NULL)
	{
		secondLast = last;
		last = last->next;
	}

	/* Update pointers to perform rotation */
	last->next = *stack;
	(*stack)->prev = last;
	secondLast->next = NULL;
	last->prev = NULL;
	*stack = last;
}
