#include "monty.h"

/**
 * rotl  .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void rotl(stack_t **stack, unsigned int ln)
{
	int tp = 0;
	stack_t *c = NULL;

	UNUSED(ln);
	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		tp = (*stack)->n;
		c = *stack;
		while (c->next)
		{
			c->n = c->next->n;
			c = c->next;
		}
		c->n = tp;
	}
}

/**
 * rotr .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void rotr(stack_t **stack, unsigned int ln)
{
	int las = 0;
	stack_t *c = NULL;

	UNUSED(ln);

	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		c = *stack;

		while (c->next != NULL)
		{
			las = c->n;
			c = c->next;
		}

		las = c->n;

		while (c->prev != NULL)
		{
			c->n = c->prev->n;
			c = c->prev;
		}

		(*stack)->n = las;
	}
}
