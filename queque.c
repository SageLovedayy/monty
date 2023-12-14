#include "monty.h"

/**
 * pushQueue - add descr
 *@head: add descr
 *@n: add descr
 *Return: new node or null
*/
stack_t *pushQueue(stack_t **head, const int n)
{
	stack_t *new, *last;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;

	return (new);
}
