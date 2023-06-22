#include "monty.h"

/**
 * pint .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void pint(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		ppint(ln);

	printf("%d\n", (*stack)->n);
}
/**
 * ppint .
 * @ln: Line number of the current operation
 */
void ppint(int ln)
{

	fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * swap .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void swap(stack_t **stack, unsigned int ln)
{
	int temp;

	if (stack == NULL || *stack == NULL)
		pswap(ln);

	if ((*stack)->next)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
		pswap(ln);
}
/**
 * pswap .
 * @ln: Line number of the current operation
 */

void pswap(int ln)
{

	fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}
