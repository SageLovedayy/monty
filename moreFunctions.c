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
