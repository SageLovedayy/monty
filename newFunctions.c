#include "monty.h"

/**
 * op_div - Perform a division operation on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	size_t elements = len(*stack);
	int divisor;

	if (elements < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);

		free(current_state.line);
		if (current_state.file)
			fclose(current_state.file);

		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);

		free(current_state.line);
		if (current_state.file)
			fclose(current_state.file);

		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	popStack(stack);
	(*stack)->n /= divisor;
}


/**
 * op_mul - Perform a multiplication operation on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	size_t elements = len(*stack);
	int factor;

	if (elements < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);

		free(current_state.line);
		if (current_state.file)
			fclose(current_state.file);

		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	factor = (*stack)->n;

	popStack(stack);
	(*stack)->n *= factor;
}


/**
 * op_mod - returns the remainder of int division
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	size_t elements = len(*stack);
	int divisor;

	if (elements < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);

		free(current_state.line);
		if (current_state.file)
			fclose(current_state.file);

		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);

		free(current_state.line);
		if (current_state.file)
			fclose(current_state.file);

		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	popStack(stack);
	(*stack)->n *= divisor;
}


/**
 * op_pchar - Print the character at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);

		free(current_state.line);
		if (current_state.file)
			fclose(current_state.file);

		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;

	if (!isascii(ascii_value))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);

		free(current_state.line);
		if (current_state.file)
			fclose(current_state.file);

		emptyStack(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(ascii_value);
	putchar('\n');
}

/**
 * op_pstr - Print the string starting from the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!stack || !(*stack))
	{
		putchar('\n');
		return;
	}

	while (temp && is_ascii_and_nonzero(temp->n))
	{
		putchar(temp->n);
		temp = temp->next;
	}

	putchar('\n');
}
