#ifndef _MONTY_
#define _MONTY_

#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

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

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

typedef void (*op_func)(stack_t **, unsigned int);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void error_shatz(unsigned int error_codes, ...);
void error_shatz2(unsigned int error_codes, ...);
void open_file(char *file_name);
void read_file(FILE *file_descriptor);
int interpret_line(char *string, int line_number, int format);
void search_function(char *opcode, char *cmd, int n_line, int format);
void find_f(op_func f, char *opcode, char *cmd, int n_line, int format);
void swap_elements(stack_t **stack, unsigned int line_number);
void add_elements(stack_t **stack, unsigned int line_number);
void subtract_elements(stack_t **stack, unsigned int line_number);
void divide_elements(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void multi(stack_t **stack, unsigned int line_number);
int main(int argc, char **argv);
stack_t *create_node(int data);
void free_nodes(void);
void add_queue(queue_t **queue, queue_t *new_node, unsigned int line_number);
void push_stack(stack_t **stack, stack_t *new_node, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);

#endif
