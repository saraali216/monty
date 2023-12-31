#include "monty.h"

/**
 * stack .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */

void stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	data.data_mode = STACK;
}


/**
 * queue .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */

void queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	data.data_mode = QUEUE;
}
