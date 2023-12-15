#include "monty.h"

/**
 * op_rotl - Rotate the stack to the top (left)
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	size_t elements = len(*stack);
	int value;

	if (elements < 2)
		return;

	value = (*stack)->n;

	popStack(stack);
	pushQueue(stack, value);
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
