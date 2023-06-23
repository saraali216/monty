#include "monty.h"

/**
 * free_stack - free all the elements
 * @hd: points to stack_t's head
 * Return: nothing to return
 */
void free_stack(stack_t *hd)
{
	stack_t *x_crrnt;

	x_crrnt = hd;
	while (hd)
	{
		x_crrnt = hd;
		hd = hd->next;
		if (x_crrnt)
			free(x_crrnt);
	}
}
