#include "monty.h"

/**
 * new_nodes - Create a new node.
 * @n: Number to host inside the node.
 * Return: On succes point to a node otherwise NULL.
 */
stack_t *new_nodes(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_exit(4);
	new->next = NULL;
	new->prev = NULL;
	new->n = n;
	return (new);
}
/**
 * free_nodes - Free a list.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
