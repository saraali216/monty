#include "monty.h"

/**
 * pchar .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void pchar(stack_t **stack, unsigned int ln)
{
	int number;

	if (stack == NULL || *stack == NULL)
		pchar_stack_empty(ln);

	number = (*stack)->n;
	if ((number >= 65 && number <= 90) || (number >= 97 && number <= 122))
		printf("%c\n", number);
	else
		pchar(ln);
}

/**
 * pstr .
 * @stack: Pointer to the top of the stack
 * @ln: Line number of the current operation
 */

void pstr(stack_t **stack, unsigned int ln)
{
	stack_t *c;

	UNUSED(ln);
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
 * @ln: Line number of the current operation
 */

void ppchar(int ln)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pchar_stack_empty.
 * @ln: Line number of the current operation
 */

void pchar_stack_empty(int ln)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
	free_all();
	exit(EXIT_FAILURE);
}
