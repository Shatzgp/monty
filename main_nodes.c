#include "monty.h"

/**
 * create_node - Create a new node.
 * @data: Data to be stored inside the node.
 * Return: On success, returns a pointer to the new node; otherwise,
 * returns NULL.
 */
stack_t *create_node(int data)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		error_shatz(4);

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = data;

	return (new_node);
}

/**
 * free_nodes - Free the entire list.
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
