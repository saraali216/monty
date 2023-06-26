#include "monty.h"

/**
 * pall: prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */

void pall(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	print_stack(*stack);
}

/**
 * push:pushes an element to the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */

void push(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (data.arg2)
	{
		if (is_num(data.arg2))
		{
			n = atoi(data.arg2);
			if (data.data_mode == STACK)
				add_node(stack, n);
			else
				add_stackint_end(stack, n);
		}
		else
			ppush_error(line_number);

	}
	else
		ppush_error(line_number);
}
/**
 * ppush_error:prints errro of push .
 * @line_number: Line number of the current operation
 */

void ppush_error(int line_number)
{

	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * free_all - deletes all.
 */

void free_all(void)
{
	free_stack(data.stack);
	fclose(data.file);
	free(data.l);
}
