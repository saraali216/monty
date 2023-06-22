#include "monty.h"

void pop(stack_t **stack, unsigned int ln)
{
	if(stack == NULL || *stack == NULL)
		print_empty_stack_error(ln);
	
	delete_top_node(stack);
}

void nop(stack_t **stack, unsigned int ln)
{
	UNUSED(stack);
	UNUSED(ln);
}

void print_empty_stack_error(int ln)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
	free_everything();
	exit(EXIT_FAILURE);
}
