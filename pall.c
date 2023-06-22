#include "monty.h"

/**
 * pall .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void pall(stack_t **stack, unsigned int ln)
{
	UNUSED(ln);
	print_stack(*stack);
}

/**
 * push .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void push(stack_t **stack, unsigned int ln)
{
	int number = 0;

	if (my_data.arg2)
	{
		if (is_num(my_data.arg2))
		{
			number = atoi(my_data.arg2);
			if (my_data.mode == STACK)
				add_node(stack, number);
			else
				add_stackint_end(stack, number);
		}
		else
			ppush_error(ln);

	}
	else
		ppush_error(ln);
}
/**
 * ppush_error .
 * @ln: Line number of the current operation
 */

void ppush_error(int ln)
{

	fprintf(stderr, "L%d: usage: push integer\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * free_all - .
 */

void free_all(void)
{
	free_stack(my_data.stack);
	fclose(my_data.file);
	free(my_data.line);
}
