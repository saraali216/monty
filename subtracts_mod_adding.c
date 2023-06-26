#include "monty.h"

/**
 * add - adding to the stack .
 * @stack: Pointer to stack
 * @line_number: current operation's line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		padd(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		delete_top(stack);
	}
	else
		padd(line_number);
}

/**
 * padd- prints the error
 * @line_number: current operation's line number
 */

void padd(int line_number)
{

	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * sub - Subtracks
 * @stack: stack's pointer
 * @line_number: current operation's number line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		psub(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		delete_top(stack);
	}
	else
		psub(line_number);
}


/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: stack's pointer
 * @line_number: current operation's number line
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		pmod(line_number);

	if ((*stack)->next)
	{
		if ((*stack)->n == 0)
			pdiv_zero(line_number);
		(*stack)->next->n %= (*stack)->n;
		delete_top(stack);
	}
	else
		pmod(line_number);
}
