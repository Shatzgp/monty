#include "monty.h"

/**
 * multi - Multiplies the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number where the opcode is encountered.
 */
void multi(stack_t **stack, unsigned int line_number)
{
    int result;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        error_shatz2(8, line_number, "mul");

    *stack = (*stack)->next;
    result = (*stack)->n * (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
    (*stack)->n = result;
}
