#include "monty.h"

/**
 * pint - Print the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fclose(current_state.file);
		free(current_state.line);

		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		emptyStack(*stack);
		exit(EXIT_FAILURE);

		return;
	}

	printf("%d\n", (*stack)->n);
}
