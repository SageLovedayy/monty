#include "monty.h"


/*Functions=====================*/
/**
 * push - add descr
 *@stack: stack
 *@line_number: line number
*/
void push(stack_t **stack, unsigned int line_number)
{
	/* Get the next token from the input line */
	current_state.token = strtok(NULL, current_state.delim);

	/* Check if the token is NULL */
	if (!current_state.token)
	{
		handle_error(line_number, *stack);
		return;
	}

	/* Check if the token is a valid number */
	if (is_number(current_state.token) != 0)
	{
		printf("not a number: %s\n", current_state.token);
		handle_error(line_number, *stack);
		return;
	}

	/* Perform different operations based on the current mode */
	if (current_state.mode == STACK)
		pushStack(stack, atoi(current_state.token)); /* Push onto stack */

	else
		pushQueue(stack, atoi(current_state.token)); /* Push onto queue */
}

/**
 * handle_error - add descr
 * @line_number: add descr
 * @stack: add descr
 */
void handle_error(unsigned int line_number, stack_t *stack)
{
	/* Cleanup */
	fclose(current_state.file);
	free(current_state.line);

	/* Handle failure */
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	emptyStack(stack);
	exit(EXIT_FAILURE);
}

/**
 * pall - stack op pall
 * @stack: stack
 * @line_number: line number
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	pall_stack(*stack);
}

