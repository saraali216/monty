#include "monty.h"

/**
 * pmalloc- prints error of malloc .
 */
void pmalloc(void)
{
	free_all();
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}

/**
 * pinvalid_instruction-Prints an error message and exits when an
 * unrecognized opcode is encountered
 * @ln: current operation's line number
 * @opcode_instruction: points to unrecognized opcode
 */
void pinvalid_instruction(int ln, char *opcode_instruction)
{

	fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode_instruction);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pusage -prints the usage error file
 */
void pusage(void)
{
	fprintf(stderr, "USAGE: the monty file :\n");
	exit(EXIT_FAILURE);
}

/**
 * open_file_error-prints the file name has the error
 * @fn: file name
 */
void open_file_error(char *fn)
{
	fprintf(stderr, "Error: Can't open the file %s\n", fn);
	exit(EXIT_FAILURE);
}
