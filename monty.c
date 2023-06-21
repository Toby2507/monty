#include "monty.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0 (success)
 */
int main(int ac, char **av)
{
	FILE *f_in;
	instruction_t *insts = op_list();
	char line_inst[255];
	int line_no = 1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_in = open(av[1], "r");
	if (!f_in)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line_inst, 255, f_in))
	{
	}
	fclose(f_in);
	return (0);
}