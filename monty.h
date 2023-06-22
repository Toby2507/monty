#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stacks_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stacks_t **stack, FILE *f_in, unsigned int line_no);
} instruction_t;

typedef void (*op_action)(stacks_t **stack, FILE *f_in, unsigned int line_no);
extern char *l_type;

void op_pchar(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_stack(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_queue(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_pall(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_swap(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_pint(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_pstr(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_rotl(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_rotr(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_pop(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_add(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_nop(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_sub(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_div(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_mul(stacks_t **stack, FILE *f_in, unsigned int line_no);
void op_mod(stacks_t **stack, FILE *f_in, unsigned int line_no);
void l_insert(stacks_t **stack, FILE *f_in, int val);
void free_list(stacks_t *stack);
op_action op_get(char *op);
void trim_in(char *str);
int isInt(char *str);

#endif /** MONTY_H **/
