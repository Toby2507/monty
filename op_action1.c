#include "monty.h"

/**
 * op_add - add the top 2 elements of the stack
 * @stack: stack head / front
 * @line_no: line_no
 */
void op_add(stacks_t **stack, unsigned int line_no)
{
	stacks_t *first = *stack, *second = NULL;
	int added;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	second = first->next;
	added = first->n + second->n;
	second->n = added;
	second->prev = NULL;
	*stack = second;
	free(first);
}

/**
 * op_sub - subtracts the top from the second top element of the stack
 * @stack: stack head / front
 * @line_no: line_no
 */
void op_sub(stacks_t **stack, unsigned int line_no)
{
	stacks_t *first = *stack, *second = NULL;
	int sub;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_no);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	second = first->next;
	sub = second->n - first->n;
	second->n = sub;
	second->prev = NULL;
	*stack = second;
	free(first);
}

/**
 * op_mul - multiplies the second top with the top element of the stack
 * @stack: stack head / front
 * @line_no: line_no
 */
void op_mul(stacks_t **stack, unsigned int line_no)
{
	stacks_t *first = *stack, *second = NULL;
	int mul;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_no);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	second = first->next;
	mul = second->n * first->n;
	second->n = mul;
	second->prev = NULL;
	*stack = second;
	free(first);
}

/**
 * op_div - divides the second top by the top element of the stack
 * @stack: stack head / front
 * @line_no: line_no
 */
void op_div(stacks_t **stack, unsigned int line_no)
{
	stacks_t *first = *stack, *second = NULL;
	int div;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	second = first->next;
	div = second->n / first->n;
	second->n = div;
	second->prev = NULL;
	*stack = second;
	free(first);
}

/**
 * op_mod - modulus of the second top and the top element of the stack
 * @stack: stack head / front
 * @line_no: line_no
 */
void op_mod(stacks_t **stack, unsigned int line_no)
{
	stacks_t *first = *stack, *second = NULL;
	int div;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_no);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	second = first->next;
	div = second->n % first->n;
	second->n = div;
	second->prev = NULL;
	*stack = second;
	free(first);
}
