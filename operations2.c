#include "monty.h"

/**
 * _add - Perform an addition operation on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	size_t elements = len(*stack);
	int first_value;

	if (elements < 2)
	{
		fclose(current_state.file);
		free(current_state.line);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	first_value = (*stack)->n;
	popStack(stack);
	(*stack)->n += first_value;
}
