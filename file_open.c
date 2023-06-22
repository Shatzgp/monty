#include "monty.h"

/**
 * open_file - Opens a file.
 * @file_name: Name of the file.
 */
void open_file(char *file_name)
{
	int access_check;
	FILE *file_descriptor;

	if (file_name == NULL)
		error_shatz(2, file_name);

	access_check = access(file_name, R_OK);
	if (access_check == -1)
		error_shatz(2, file_name);

	file_descriptor = fopen(file_name, "r");
	if (file_descriptor == NULL)
		error_shatz(2, file_name);

	read_file(file_descriptor);

	fclose(file_descriptor);
}

/**
 * read_file - Reads the contents of a file line by line.
 * @file_descriptor: Pointer to the file descriptor.
 */
void read_file(FILE *file_descriptor)
{
	int line_number = 1;
	int format = 0;
	char *buffer = NULL;
	size_t buffer_size = 0;

	if (file_descriptor == NULL)
		error_shatz(2, "file_name");

	while (getline(&buffer, &buffer_size, file_descriptor) != EOF)
	{
		format = interpret_line(buffer, line_number, format);
		line_number++;
	}

	free(buffer);
}

/**
 * interpret_line - Interprets each line by separating it into tokens.
 * @string: String representing a line.
 * @line_number: Line number for the opcode.
 * @format: Format specifier: 0 for stack, 1 for queue.
 * Return: 0 if opcode is "stack", 1 if opcode is "queue".
 */
int interpret_line(char *string, int line_number, int format)
{
	char *opcode;
	char *argument;
	const char *delimiter = "\n ";

	if (string == NULL)
		error_shatz(4);

	opcode = strtok(string, delimiter);

	if (opcode == NULL)
		return (format);

	argument = strtok(NULL, delimiter);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	search_function(opcode, argument, line_number, format);
	return (format);
}
