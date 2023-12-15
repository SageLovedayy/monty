#include "monty.h"

/**
 * op_rotl - Rotate the stack to the top (left)
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
		return;

	/* Remove the top element from the stack */
	popStack(stack);

	/* Traverse the stack to find the last node */
	while (temp->next != NULL)
		temp = temp->next;

	/* Make the removed element the last node */
	temp->next = *stack;
	(*stack)->prev = temp;

	/* Update the stack to point to the new top element */
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}
