#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <sys/types.h>



/*----------------------------------------------------------*/
/**
 * enum modes - operation modes
 * @STACK: stack mode
 * @QUEUE: queue mode
 */
enum modes
{
	STACK,
	QUEUE
};

/**
 * struct input_state - state variable
 * @token: token
 * @delim: delim
 * @file: file pointer
 * @line: file line
 * @mode: op mode
 */
typedef struct input_state
{
	char *token;
	char *delim;
	FILE *file;
	char *line;
	int mode;

} input_state;



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/*--------------------------------------------------------*/
/**
 * struct OpcodeHandler - Opcode and its corresponding function handler
 * @opcode: The opcode string
 * @handler: Pointer to the function that handles the opcode
 *
 * Description: This struct associates an opcode with its corresponding
 * function handler for stack, queues, LIFO, FIFO operations.
 */
typedef struct OpcodeHandler
{
	char *opcode;
	void (*handler)(stack_t **stack, unsigned int line_number);
} OpcodeHandler;



extern input_state current_state;
/*---------------------------------------------------------*/
/*PROTOTYPES=======*/
void (*get(char *opcode))(stack_t **stack, unsigned int line_num);
stack_t *pushStack(stack_t **head, const int n);
size_t pall_stack(const stack_t *h);
void emptyStack(stack_t *head);

stack_t *pushQueue(stack_t **head, const int n);

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void handle_error(unsigned int line_number, stack_t *stack);
void push(stack_t **stack, unsigned int line_number);

int is_number(const char *n);

/* Function to initialize the input state */
void initInputState(input_state *state, char *delim);

/* Function to handle opcode "stack" or "queue" */
void handleModeOpcode(input_state *state);

/* Function to execute the opcode operation */
void executeOpcode(input_state *state, stack_t **stack, unsigned int line_num);

/* Function to handle unknown opcode */
void handleUnknownOpcode(input_state *state
, stack_t *stack, unsigned int line_num);

/* Function to free memory and close the file */
void cleanupAndExit(input_state *state, stack_t *stack, unsigned int line_num);

#endif /*monty.h*/