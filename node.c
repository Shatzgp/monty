#include "monty.h"

/**
 * add_queue - Adds a node to the queue.
 * @queue: Pointer to the queue.
 * @new_node: Pointer to the new node.
 * @line_number: Integer representing the line number of the opcode.
 */
void add_queue(queue_t **queue, queue_t *new_node, unsigned int line_number)
{
	queue_t *tmp;
	(void)line_number;

	if (queue == NULL || new_node == NULL)
		exit(EXIT_FAILURE);

	if (*queue == NULL)
	{
		*queue = new_node;
		return;
	}

	tmp = *queue;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = NULL;
}

/**
 * push_stack - Pushes a node to the stack.
 * @stack: Pointer to the stack.
 * @new_node: Pointer to the new node.
 * @line_number: Integer representing the line number of the opcode.
 */
void push_stack(stack_t **stack, stack_t *new_node, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (stack == NULL || new_node == NULL)
		exit(EXIT_FAILURE);

	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}

	tmp = *stack;
	new_node->prev = NULL;
	new_node->next = tmp;
	tmp->prev = new_node;
	*stack = new_node;
}

/**
 * print_stack - Prints all elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_stack - Removes the top element from the stack.
 * @stack: Pointer to the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		error_shatz2(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		error_shatz2(6, line_number);

	printf("%d\n", (*stack)->n);
}
