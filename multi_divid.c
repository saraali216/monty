#include "monty.h"

/**
 * mul -multiplies the second top element
 * of the stack with the top element of the stack.
 * @stack: stack's pointer
 * @line_number: current operation's number line
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		pmul(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		delete_top(stack);
	}
	else
		pmul(line_number);

}


/**
 * print_mul_error - prints error if not mul.
 * @line_number:current operation's number line
 */
void pmul(int line_number)
{

	fprintf(stderr, "L%d: can't be multiplied, stack too short\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}


/**
 * the_div - divides the second top element
 * of the stack by the top element of the stack.
 * @stack: stack's pointer
 * @line_number: current operation's number line
 */
void the_div(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		pdiv(line_number);

	if ((*stack)->next)
	{
		if ((*stack)->n == 0)
			pdiv_zero(line_number);
		(*stack)->next->n /= (*stack)->n;
		delete_top(stack);
	}
	else
		pdiv(line_number);
}


/**
 * pdiv - prints div error .
 * @line_number: current operation's number line
 */
void pdiv(int line_number)
{
	fprintf(stderr, "L%d: can't be divided, stack too short\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}


/**
 * pdiv_zero-prints 0 if error.
 * @line_number: current operation's number line
 */
void pdiv_zero(int line_number)
{

	fprintf(stderr, "L%d: division by zero\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}
