#include "monty.h"

/**
 * op_pstr - prints the string starting at the top of the stack
 * @stack: stack head / front
 * @line_no: line_no
 */
void op_pstr(stacks_t **stack, unsigned int line_no)
{
	stacks_t *curr = *stack;
	(void)line_no;

	for (; curr; curr = curr->next)
	{
		if (curr->n <= 0 || curr->n > 127)
			break;
		printf("%c", curr->n);
	}
	printf("\n");
}

/**
 * op_rotl - rotates the stack to the top
 * @stack: stack head / front
 * @line_no: line_no
 */
void op_rotl(stacks_t **stack, unsigned int line_no)
{
	stacks_t *top = *stack, *end = *stack;
	(void)line_no;

	if (!(*stack) || !(*stack)->next)
		return;
	while (end->next)
		end = end->next;
	end->next = top;
	*stack = top->next;
	(*stack)->prev = NULL;
	top->prev = end;
	top->next = NULL;
}

/**
 * op_rotr - rotates the stack to the bottom
 * @stack: stack head / front
 * @line_no: line_no
 */
void op_rotr(stacks_t **stack, unsigned int line_no)
{
	stacks_t *top = *stack, *end = *stack;
	(void)line_no;

	if (!(*stack) || !(*stack)->next)
		return;
	while (end->next)
		end = end->next;
	end->next = top;
	top->prev = end;
	end->prev->next = NULL;
	end->prev = NULL;
	*stack = end;
}

/**
 * op_stack - sets the format of the data to a stack (LIFO)
 * @stack: stack head / front
 * @line_no: line_no
 */
void op_stack(stacks_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
	l_type = "stack";
}

/**
 * op_queue - sets the format of the data to a queue (FIFO)
 * @stack: stack head / front
 * @line_no: line_no
 */
void op_queue(stacks_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
	l_type = "queue";
}
