#include "monty.h"

/**
 * op_list - stores a list of all possible op codes and action functions
 * @op: op command
 *
 * Return: list of op_codes
 */
op_action op_get(char *op)
{
	int i, no_ops = 16;
	instruction_t codes[] = {
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", op_stack},
		{"queue", op_queue}};

	for (i = 0; i < no_ops; i++)
		if (strcmp(codes[i].opcode, op) == 0)
			return (codes[i].f);
	return (NULL);
}
