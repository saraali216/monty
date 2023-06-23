#include "monty.h"

/**
 * psub - Prints an error message and terminates the program
 * if the stack is too short for the "sub" operation.
 * @ln: Line number of the current operation.
 * Return: Nothing
 */

void psub(int ln)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * is_num - Checks if a string represents a valid integer
 * @num: The string to check
 * Return: 1 if the string is a valid integer, 0 otherwise
 */

int is_num(char *num)
{
	int j = 0;

	if (num[j] == '-')
		j++;

	while (num[j])
	{
		if (!(num[j] >= '0' && num[j] <= '9'))
			return (0);
		j++;
	}

	return (1);
}
