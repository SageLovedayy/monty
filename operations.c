#include "monty.h"

/**
 * op_pint - Print the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_pint(stack_t **stack, unsigned int line_number)
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
 * op_pop - Print the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_pop(stack_t **stack, unsigned int line_number)
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

/**
 * len - Get the number of elements in the stack
 * @stack: Pointer to the stack
 * Return: Number of elements
 */
size_t len(stack_t *stack)
{
	size_t count = 0;
	stack_t *current = stack;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}



/**
 * op_swap - Perform a swap operation on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	size_t elements = len(*stack);
	int first_value;
	int second_value;

	if (elements < 2)
	{
		fclose(current_state.file);
		free(current_state.line);

		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	first_value = (*stack)->n;

	popStack(stack);

	second_value = (*stack)->n;
	(*stack)->n = first_value;
	pushStack(stack, second_value);
}


