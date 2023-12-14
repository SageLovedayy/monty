#include "monty.h"

/**
 * pushStack - Function to insert a node at the end of the list
 * @head: add descr
 * @n: add descr
 * Return: new node
*/
stack_t *pushStack(stack_t **head, const int n)
{
	stack_t *new;

	if (!head)
	{
		return (NULL);
	}

	new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * pall_stack - add descr
 * @h: add descr
 *Return: nodes
*/
size_t pall_stack(const stack_t *h)
{
	size_t nodes = 0;

	for (; h; nodes++, h = h->next)
		printf("%d\n", h->n);

	return (nodes);
}

/**
 * emptyStack - empties stack
 * @head: The head of the stack_t list.
 */
void emptyStack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
