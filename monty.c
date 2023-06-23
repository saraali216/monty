#include "monty.h"

/**
 * main - Entry point for the Monty interpreter program
 * @argv: arguments array of strings
 * @argc: arguments number
 * Return: 0 success, -1 failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		pusage();
	return (execf(argv[1]));

}
