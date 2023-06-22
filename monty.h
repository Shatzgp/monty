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
void open_file(char *file_name);
void r_file(FILE *fd);
int int_line(char *string, int n_line, int format);
void error_exit2(unsigned int error_code, ...);
void error_exit(unsigned int error_code, ...);
void srch_function(char *opcode, char *cmd, int n_line, int format);
void swaps(stack_t **stack, unsigned int n_line);
void adds(stack_t **stack, unsigned int n_line);
void subs(stack_t **stack, unsigned int n_line);
void division(stack_t **stack, unsigned int n_line);
void nope(stack_t **stack, unsigned int n_line);
void multi(stack_t **stack, unsigned int n_line);
int main(int argc, char **argv);
stack_t *new_nodes(int n);
void free_nodes(void);
void add_queues(stack_t **new_node, unsigned int n_line);
void pushs(stack_t **new_node, unsigned int n_line);
void pall(stack_t **stack, unsigned int n_line);
void pop(stack_t **stack, unsigned int n_line);
void pint(stack_t **stack, unsigned int n_line);

#endif