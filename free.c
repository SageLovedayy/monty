#include "monty.h"

/**
 *freeStack - frees stack
 *@head: head
 */
void freeStack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

