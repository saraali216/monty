#include "monty.h"

/**
 * mul -multiplies the second top element
 * of the stack with the top element of the stack.
 * @stack: stack's pointer
 * @ln: current operation's number line
 */
void mul(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		pmul(ln);

	if ((*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		delete_top(stack);
	}
	else
		pmul(ln);

}


/**
 * print_mul_error - prints error if not mul.
 * @ln:current operation's number line
 */
void pmul(int ln)
{

	fprintf(stderr, "L%d: can't be multiplied, stack too short\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}


/**
 * the_div - divides the second top element
 * of the stack by the top element of the stack.
 * @stack: stack's pointer
 * @ln: current operation's number line
 */
void the_div(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		pdiv(ln);

	if ((*stack)->next)
	{
		if ((*stack)->n == 0)
			pdiv_zero(ln);
		(*stack)->next->n /= (*stack)->n;
		delete_top(stack);
	}
	else
		pdiv(ln);
}


/**
 * pdiv - prints div error .
 * @ln: current operation's number line
 */
void pdiv(int ln)
{
	fprintf(stderr, "L%d: can't be divided, stack too short\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}


/**
 * pdiv_zero-prints 0 if error.
 * @ln: current operation's number line
 */
void pdiv_zero(int ln)
{

	fprintf(stderr, "L%d: division by zero\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}
