#include "monty.h"

/**
 * pall: prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void pall(stack_t **stack, unsigned int ln)
{
	UNUSED(ln);
	print_stack(*stack);
}

/**
 * push:pushes an element to the stack.
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void push(stack_t **stack, unsigned int ln)
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
			ppush_error(ln);

	}
	else
		ppush_error(ln);
}
/**
 * ppush_error:prints errro of push .
 * @ln: Line number of the current operation
 */

void ppush_error(int ln)
{

	fprintf(stderr, "L%d: usage: push integer\n", ln);
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
