#include "monty.h"

/**
 * pchar prints char.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (stack == NULL || *stack == NULL)
		pchar_stack_empty(line_number);

	n = (*stack)->n;
	if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122))
		printf("%c\n", n);
	else
		ppchar(line_number);
}

/**
 * pstr .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *c;

	UNUSED(line_number);
	c = *stack;
	while (c)
	{
		if ((c->n >= 65 && c->n <= 90) || (c->n >= 97 && c->n <= 122))
		{
			printf("%c", c->n);
			c = c->next;
		}
		else
			break;
	}
	printf("\n");
}

/**
 * pchar.
 * @line_number: Line number of the current operation
 */

void ppchar(int line_number)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pchar_stack_empty.
 * @line_number: Line number of the current operation
 */

void pchar_stack_empty(int line_number)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}
