#include "monty.h"

/**
 * search_function - Finds the function to execute.
 * @opcode: Operation code.
 * @cmd: Possible value for operation.
 * @n_line: Line number for opcode.
 * @format: Format specifier (0 for Stack, 1 for Queue).
 */
void search_function(char *opcode, char *cmd, int n_line, int format)
{
	int i, error;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", mult},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	for (error = 1, i = 0; functions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
		{
			find_function(functions[i].function, opcode, cmd, n_line, format);
			error = 0;
		}
	}
	if (error == 1)
		error_shatz(3, n_line, opcode);
}

/**
 * find_f - Executes the required function.
 * @f: Pointer to the function to call.
 * @opcode: String representing opcode.
 * @cmd: String representing numeric value.
 * @n_line: Line number for instruction.
 * @format: Format specifier.
 */
void find_f(op_func f, char *opcode, char *cmd, int n_line, int format)
{
	stack_t *node;
	int error, i;

	error = 1;

	if (strcmp(opcode, "push") == 0)
	{
		if (cmd != NULL && cmd[0] == '-')
		{
			cmd = cmd + 1;
			error = -1;
		}
		if (cmd == NULL)
			error_shatz(5, n_line);
		for (i = 0; cmd[i] != '\0'; i++)
		{
			if (isdigit(cmd[i]) == 0)
				error_shatz(5, n_line);
		}
		node = new_node(atoi(cmd) * error);
		if (format == 0)
			function(&node, n_line);
		if (format == 1)
			add_queue(&node, n_line);
	}
	else
		function(&head, n_line);
}
