#include "monty.h"

/**
 * swaps - Swap element 1 for element 2 of the stack.
 * @stack: Points to the top node of the stack.
 * @n_line: Opcode line number.
 */
void swaps(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_exit2(8, n_line, "swaps");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * adds - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @n_line: Interger representing the line number of of the opcode.
 */
void adds(stack_t **stack, unsigned int n_line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_exit2(8, n_line, "adds");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subs - Substrac the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @n_line: Interger representing the line number of of the opcode.
 */
void subs(stack_t **stack, unsigned int n_line)
{
	int subs;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_exit2(8, n_line, "subs");

	(*stack) = (*stack)->next;
	subs = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = subs;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * division - Division the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @n_line: Interger representing the line number of of the opcode.
 */
void division(stack_t **stack, unsigned int n_line)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_exit2(8, n_line, "div");

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n_line);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nope - Does nothing.
 * @stack: Top of the stack.
 * @n_line: Current line number.
 */
void nope(stack_t **stack, unsigned int n_line)
{
	(void)*stack;
	(void)n_line;
}
