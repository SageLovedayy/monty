#include "monty.h"

/**
 * op_add - Perform an addition operation on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	size_t elements = len(*stack);
	int first_value;

	if (elements < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);

		free(current_state.line);
		if (current_state.file)
			fclose(current_state.file);

		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	first_value = (*stack)->n;
	popStack(stack);
	(*stack)->n += first_value;
}


/**
 * op_nop - stack op nop
 * @stack: stack
 * @line_number: line number
 */
void op_nop(__attribute__((unused)) stack_t **stack
, __attribute__((unused)) unsigned int line_number)
{ }

/**
 * op_sub - Perform a subtraction operation on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	size_t elements = len(*stack);
	int subtractor;

	if (elements < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(current_state.line);
		if (current_state.file)
			fclose(current_state.file);

		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	subtractor = (*stack)->n;
	popStack(stack);
	(*stack)->n -= subtractor;
}
