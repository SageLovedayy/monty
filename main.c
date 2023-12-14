#include "monty.h"

input_state current_state = {
	NULL,
	"\n\t\a\r ;:",
	NULL,
	NULL,
	STACK
};

/**
 * main - entry point
 *@argv: argument vector
 *@argc: argument count
 *Return: 0 or 1
*/
int main(int argc, char **argv)
{
	input_state current_state;
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_num;

	/* Check for correct number of command-line arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* Initialize the input state */
	initInputState(&current_state, "\n\t\a\r ;:");
	/* Open the file specified in the command-line argument in read-only mode */
	current_state.file = fopen(argv[1], "r");
	/* Check if the file could be opened successfully */
	if (!current_state.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* Loop through each line in the file */
	for (line_num = 1; (read = getline(&current_state.line, &len
	, current_state.file)) != EOF; line_num++)
	{
		/* Tokenize the current line and execute opcode */
		executeOpcode(&current_state, &stack, line_num);
	}
	/* Free memory and close the file */
	cleanupAndExit(&current_state, stack, line_num);
	/*free(stack);*/
	return (0);
}



/*==========================================================*/
/**
 * get - add descr
 *@opcode: opcode
 * Return: handler function
*/
void (*get(char *opcode))(stack_t **stack, unsigned int line_num)
{
	OpcodeHandler operationMap[] = {
	{"push", push},
	{"pall", pall},
	/*{"pint", pint},*/
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
