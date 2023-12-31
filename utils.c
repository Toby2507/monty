#include "monty.h"

/**
 * l_insert - inserts a new value into the list
 * @stack: stack head
 * @f_in: input file
 * @val: new value
 */
void l_insert(stacks_t **stack, FILE *f_in, int val)
{
	stacks_t *l_new = malloc(sizeof(stacks_t)), *curr = *stack;

	if (!l_new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*stack);
		fclose(f_in);
		exit(EXIT_FAILURE);
	}
	l_new->n = val;
	l_new->next = NULL;
	l_new->prev = NULL;
	if (!(*stack))
	{
		*stack = l_new;
		return;
	}
	if (strcmp(l_type, "stack") == 0)
	{
		l_new->next = *stack;
		(*stack)->prev = l_new;
		*stack = l_new;
	}
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = l_new;
		l_new->prev = curr;
	}
}

/**
 * op_nop - does nothing
 * @stack: stack head / front
 * @f_in: input file
 * @line_no: line_no
 */
void op_nop(stacks_t **stack, FILE *f_in, unsigned int line_no)
{
	(void)stack;
	(void)f_in;
	(void)line_no;
}

/**
 * trim_in - remove all the whitespace at the beginning of the string
 * @str: string to be trimmed
 */
void trim_in(char *str)
{
	int start = 0, end, len, i, j;

	if (!str)
		return;
	len = strlen(str);
	end = len - 1;
	while (isspace(str[start]))
		start++;
	while (end >= start && isspace(str[end]))
		end--;
	for (i = 0, j = start; j <= end; i++, j++)
		str[i] = str[j];
	str[i] = '\0';
}

/**
 * isInt - check if the strings are integers
 * @str: string under review
 *
 * Return: 1 on success, 0 otherwise
 */
int isInt(char *str)
{
	if (!str || !(*str))
		return (0);
	for (; *str; str++)
		if (!isdigit(*str) && *str != '-')
			return (0);
	return (1);
}

/**
 * free_list - free the list
 * @stack: stack head
 */
void free_list(stacks_t *stack)
{
	stacks_t *curr = stack, *next = NULL;

	for (; curr; curr = next)
	{
		next = curr->next;
		free(curr);
	}
}
