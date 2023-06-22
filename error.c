#include "monty.h"
/**
 * error_shatz - Prints error messages.
 * @error_codes: The error codes are the following.
 */
void error_shatz(unsigned int error_codes, ...)
{
	va_list ag;
	char *opp_errors;
	unsigned int line_count;

	va_start(ag, error_codes);

	switch (error_codes)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(ag, char *));
			break;
		case 3:
			line_count = va_arg(ag, unsigned int);
			opp_errors = va_arg(ag, char *);
			fprintf(stderr, "L%u: unknown instruction %s\n", line_count, opp_errors);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%u: usage: push integer\n", va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * error_shatz2 - Handles errors.
 * @error_codes: The error codes are the following.
 */
void error_shatz2(unsigned int error_codes, ...)
{
	va_list ag;
	char *opp_errors;
	unsigned int n_line;

	va_start(ag, error_codes);
	switch (error_codes)
	{
		case 6:
			fprintf(stderr, "L%u: can't pint, stack empty\n",
					va_arg(ag, unsigned int));
			break;
		case 7:
			fprintf(stderr, "L%u: can't pop an empty stack\n",
					va_arg(ag, unsigned int));
			break;
		case 8:
			n_line = va_arg(ag, unsigned int);
			opp_errors = va_arg(ag, char *);
			fprintf(stderr, "L%u: can't %s, stack too short\n", n_line, opp_errors);
			break;
		case 9:
			n_line = va_arg(ag, unsigned int);
			opp_errors = va_arg(ag, char *);
			fprintf(stderr, "L%u: can't div %s, stack too short \n",
					n_line, opp_errors);
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

