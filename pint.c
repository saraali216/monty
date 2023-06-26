#include "monty.h"

/**
 * pint .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		ppint(line_number);

	printf("%d\n", (*stack)->n);
}
/**
 * ppint .
 * @line_number: Line number of the current operation
 */
void ppint(int line_number)
{

	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * swap .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL)
		pswap(line_number);

	if ((*stack)->next)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
		pswap(line_number);
}
/**
 * pswap .
 * @line_number: Line number of the current operation
 */

void pswap(int line_number)
{

	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}
