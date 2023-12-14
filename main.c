#include "main.h"
#include "input_state.h"

/**
 * main - entry point
 *@argv: argument vector
 *@argc: argument count
 *Return: 0 or 1
*/
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_num;
	unsigned int check_line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*open argv1 in read only mode*/
	current_state.file = fopen(argv[1], "r");

	/*cant' open file*/
	if (!current_state.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (line_num = 1; (read = getline(&current_state.line, &len, current_state.file)) != EOF; line_num++)
	{
		for (current_state.token = strtok(current_state.line, current_state.delim); current_state.token;)
		{
			check_line = 1;

			if (current_state.token[0] == '#') /*monty comments*/
				break;

			if (!strcmp(current_state.token, "stack"))
			{
				current_state.mode = STACK;
				break;
			}

			if (!strcmp(current_state.token, "queue"))
			{
				current_state.mode = QUEUE;
				break;
			}

			if (get(current_state.token))
				get(current_state.token)(&stack, line_num);

			else
			{
				fclose(current_state.file);
				emptyStack(stack);
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, current_state.token);
				free(current_state.token);
				exit(EXIT_FAILURE);
			}

			break;

		}
	}

	if (!check_line)
		free(current_state.line);

	emptyStack(stack);
	free(current_state.token);
	fclose(current_state.file);

	return (0);
}


void (*get(char *opcode))(stack_t **stack, unsigned int line_num)
{
	OpcodeHandler operationMap[] = {
	{"push", push},
	{"pall", pall},
	/*add more*/
	{NULL, NULL}};

	int i;

	for (i = 0; operationMap[i].opcode; i++)
	{
		if (!strcmp(opcode, operationMap[i].opcode))
			return (operationMap[i].handler);
	}

	return (NULL);
}


/*Functions=====================*/
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

