#include "monty.h"

/**
 * op_pop - removes the top element of the stack
 * @stack: stack head / front
 * @f_in: file input
 * @line_no: line_no
 */
void op_pop(stacks_t **stack, FILE *f_in, unsigned int line_no)
{
	stacks_t *popped = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
		free_list(*stack);
		fclose(f_in);
		exit(EXIT_FAILURE);
	}
	*stack = popped->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(popped);
}

/**
 * op_pint - prints the value at the top of the stack
 * @stack: stack head / front
 * @f_in: file input
 * @line_no: line_no
 */
void op_pint(stacks_t **stack, FILE *f_in, unsigned int line_no)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		free_list(*stack);
		fclose(f_in);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * op_pall - prints all the values on the stack
 * @stack: stack head / front
 * @f_in: file input
 * @line_no: line_no
 */
void op_pall(stacks_t **stack, FILE *f_in, unsigned int line_no)
{
	stacks_t *curr = *stack;
	(void)f_in;
	(void)line_no;

	for (; curr; curr = curr->next)
		printf("%d\n", curr->n);
}

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: stack head / front
 * @f_in: file input
 * @line_no: line_no
 */
void op_swap(stacks_t **stack, FILE *f_in, unsigned int line_no)
{
	stacks_t *first = *stack, *second = NULL;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_no);
		free_list(*stack);
		fclose(f_in);
		exit(EXIT_FAILURE);
	}
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	second->next = first;
	*stack = second;
}

/**
 * op_pchar - prints the char at the top of the stack
 * @stack: stack head / front
 * @f_in: file input
 * @line_no: line_no
 */
void op_pchar(stacks_t **stack, FILE *f_in, unsigned int line_no)
{
	int s_top;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
		free_list(*stack);
		fclose(f_in);
		exit(EXIT_FAILURE);
	}
	s_top = (*stack)->n;
	if (s_top < 0 || s_top > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_no);
		free_list(*stack);
		fclose(f_in);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", s_top);
}
