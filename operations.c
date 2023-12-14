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


/**
 * pop - Print the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		if (current_state.file)
			fclose(current_state.file);
		free(current_state.line);

		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		emptyStack(*stack);
		exit(EXIT_FAILURE);


	}
	popStack(stack);
	return;
}

/**
 * popStack - deletes node at end of doubly linked list
 * @h: pointer to head of doubly linked list
 */
void popStack(stack_t **h)
{
	stack_t *del = NULL;

	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}
