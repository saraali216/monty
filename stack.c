#include "monty.h"

/**
 * stack .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void stack(stack_t **stack, unsigned int ln)
{
	UNUSED(stack);
	UNUSED(ln);
	my_data.mode = STACK;
}


/**
 * queue .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void queue(stack_t **stack, unsigned int ln)
{
	UNUSED(stack);
	UNUSED(ln);
	my_data.mode = QUEUE;
}
