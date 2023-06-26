#include "monty.h"

/**
 * pop-poping
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		pempty_stack(line_number);
	delete_top(stack);
}

/**
 * nop .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */

void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

/**
 * pempty_stack .
 * @line_number: Line number of the current operation
 */

void pempty_stack(int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}
