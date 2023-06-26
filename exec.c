#include "monty.h"

/**
 * is_emptyl -testing if the line empty or not
 * @l: the line that will be checked
 * Return: 1 line is empty, 0 not empty
 */

int is_emptyl(char *l)
{
	int leng = strlen(l);
	int i;

	if (leng > 0)
	{
		if (l[leng - 1] == '\n')
		{
			for (i = 0; i < leng - 1; i++)
			{
				if (l[i] != ' ')
					return (1);
			}
			return (0);
		}
	}
	return (0);
}


/**
 * execf- executes operations in file
 * @fn: name of file that has the operations
 * Return: 0 success, -1 failure
 */
int execf(char *fn)
{
	char *l = NULL;
	FILE *file;
	ssize_t read;
	size_t lleng = 0;
	data_t data;

	data.stack = NULL;
	file = fopen(fn, "r");
	if (file == NULL)
		open_file_error(fn);
	data.file = file;
	while ((read = getline(&l, &lleng, file)) != -1)
	{
		data.line_number++;
		data.l = l;
		if (is_emptyl(data.l) == 1)
			execl(data.l, data.line_number);
	}
	free_stack(data.stack);
	fclose(file);
	free(l);
	return (0);
}


/**
 * execl- executes a single operation's line
 * @l: operation's line
 * @line_number: current operation's line number
 */
void execl(char *l, int line_number)
{
	int is_inst = -1;
	int i;
	data_t data;
	instruction_t insts[] = {
		{"push", push},
		{"sub", sub},
		{"div", the_div},
		{"add", add},
		{"mul", mul},
		{"mod", mod},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{"pchar", pchar},
		{"queue", queue},
		{"stack", stack},
	};
	data.arg1 = strtok(l, " \n");
	data.arg2 = strtok(NULL, " \n");
	if (data.arg1[0] == '#')
	{
		nop(&data.stack, line_number);
		return;
	}
	for (i = 0; i < INSTRUCTIONS_COUNT; i++)
		if (strcmp(data.arg1, insts[i].opcode) == 0)
		{

			is_inst = i;
			break;
		}
	if (is_inst != -1)
		insts[i].f(&data.stack, line_number);
	else
		pinvalid_instruction(line_number, data.arg1);
}
