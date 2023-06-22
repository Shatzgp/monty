#include "monty.h"

/**
 * srch_function - Finds the function to be executed.
 * @opcode: Operation code.
 * @cmd: Possible value 4 the operation.
 * @n_line: Line number 4 the opcode.
 * @format: Format specifier should be 0 for Stack or 1 for Queue.
 */
void srch_function(char *opcode, char *cmd, int n_line, int format)
{
	int i;
	int error;

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
			find_func(functions[i].f, opcode, cmd, n_line, format);
			error = 0;
		}
	}
	if (error == 1)
	{
		error_exit(3, n_line, opcode);
	}
}
