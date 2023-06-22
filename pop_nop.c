#include "monty.h"

/**
 * pop .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void pop(stack_t **stack, unsigned int ln)
{
	if(stack == NULL || *stack == NULL)
		pempty_stack(ln);
	
	delete_top(stack);
}

/**
 * nop .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void nop(stack_t **stack, unsigned int ln)
{
	UNUSED(stack);
	UNUSED(ln);
}

/**
 * pempty_stack .
 * @ln: Line number of the current operation
 */

void pempty_stack(int ln)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}
