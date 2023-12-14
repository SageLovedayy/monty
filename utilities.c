#include "monty.h"

/**
 *initInputState - Function to initialize the input state
 *@state: state
 *@delim: delimiter
*/
void initInputState(input_state *state, char *delim)
{
	state->token = NULL;
	state->delim = delim;
	state->file = NULL;
	state->line = NULL;
	state->mode = STACK; /* Default mode is STACK */
}

/**
 *handleModeOpcode - Function to handle opcode "stack" or "queue"
 *@state:state
 */
void handleModeOpcode(input_state *state)
{
	if (!strcmp(state->token, "stack"))
	{
		state->mode = STACK;
	}
	else if (!strcmp(state->token, "queue"))
	{
		state->mode = QUEUE;
	}
}

/**
 *executeOpcode - Function to execute opcode
 *@state:state
 *@stack: stack
 *@line_num: line number
 */
void executeOpcode(input_state *state, stack_t **stack, unsigned int line_num)
{
	int check_line = 1;

	/* Tokenize the current line */
	for (state->token = strtok(state->line, state->delim); state->token;)
	{
		/* Check if the token is a comment */
		if (state->token[0] == '#')
			break;

		/* Check if the token is "stack" or "queue" */
		handleModeOpcode(state);

		/* Execute the opcode corresponding to the token if it exists */
		if (get(state->token))
			get(state->token)(stack, line_num);
		else
		{
			/* Handle unknown opcode */
			handleUnknownOpcode(state, *stack, line_num);
		}

		/* Break from the loop */
		break;
	}

	/* Free memory if a line should not be checked */
	if (!check_line)
		free(state->line);
}


/* Function to handle unknown opcode */
void handleUnknownOpcode(input_state *state
, __attribute__((unused)) stack_t *stack, unsigned int line_num)
{

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, state->token);
	free(state->token);
	if (state->file)
		fclose(state->file);
	/*free(state->line);*/
	exit(EXIT_FAILURE);
}

/* Function to free memory and close the file */
void cleanupAndExit(input_state *state, stack_t *stack
, __attribute__((unused)) unsigned int line_num)
{
	if (!state->line)
		free(state->line);

	emptyStack(stack);
	free(state->token);
	if (state->file)
		fclose(state->file);
}
