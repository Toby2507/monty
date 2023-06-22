#include "monty.h"

char *l_type = "stack";

/**
 * handle_comm - handles op commands
 * @stack: stack top/front
 * @op_c: op command
 * @l_no: line number of op command
 */
void handle_comm(stacks_t **stack, char *op_c, unsigned int l_no)
{
	char *op_a;
	op_action op_act;

	if (op_c[0] == '#')
		return;
	if (strcmp(op_c, "push") == 0)
	{
		op_a = strtok(NULL, " ");
		if (op_a == NULL || !isInt(op_a))
		{
			fprintf(stderr, "L%u: usage: push integer\n", l_no);
			free(*stack);
			exit(EXIT_FAILURE);
		}
		l_insert(stack, atoi(op_a));
	}
	else
	{
		op_act = op_get(op_c);
		if (op_act)
			op_act(stack, l_no);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", l_no, op_c);
			free(*stack);
			exit(EXIT_FAILURE);
		}
	}
}

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
	stacks_t *stack = NULL;
	char l_inst[255], *op_c;
	unsigned int l_no = 1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_in = fopen(av[1], "r");
	if (!f_in)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(l_inst, 255, f_in))
	{
		trim_in(l_inst);
		if (*l_inst)
		{
			op_c = strtok(l_inst, " ");
			handle_comm(&stack, op_c, l_no);
		}
		l_no++;
	}
	free(stack);
	fclose(f_in);
	return (0);
}
