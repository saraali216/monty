#include "monty.h"

/**
 * pmalloc- prints error of malloc .
 */
void pmalloc(void)
{
	free_all();
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}


