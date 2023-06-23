#include "monty.h"

/**
 * add - adding to the stack .
 * @stack: Pointer to stack
 * @ln: current operation's line number
 */

void add(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		padd(ln);

	if ((*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		delete_top(stack);
	}
	else
		padd(ln);
}

/**
 * padd- prints the error
 * @ln: current operation's line number
 */

void padd(int ln)
{

	fprintf(stderr, "L%d: can't add, stack too short\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * sub - Subtracks
 * @stack: stack's pointer
 * @ln: current operation's number line
 */
void sub(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		psub(ln);

	if ((*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		delete_top(stack);
	}
	else
		psub(ln);
}


/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: stack's pointer
 * @ln: current operation's number line
 */
void mod(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		pmod(ln);

	if ((*stack)->next)
	{
		if ((*stack)->n == 0)
			pdiv_zero(ln);
		(*stack)->next->n %= (*stack)->n;
		delete_top(stack);
	}
	else
		pmod(ln);
}
