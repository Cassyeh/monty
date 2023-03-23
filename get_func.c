#include "monty.h"

/**
 * get_func - based on tokens from single line, decide what function to call
 * @stack: pointer to pointer to head of stack data structure
 * @op: operator, aka token[0] from getline
 * @line_number: line in byte-code file being processed, zero indexed
 * Return: int
 **/
void get_func(stack_t **stack, char *op, unsigned int line_number)
{
	int i = 0;
	instruction_t all_ops[] = {
		{"push", instruction_push},
		{"pall", instruction_pall},
		{"pint", instruction_pint},
		{"pop", instruction_pop},
		{"swap", instruction_swap},
		{"add", instruction_add},
		{"nop", instruction_nop},
		{"sub", instruction_sub},
		{"div", instruction_div},
		{"mul", instruction_mul},
		{"mod", instruction_mod},
		{"pchar", instruction_pchar},
		{"pstr", instruction_pstr},
		{"rotl", instruction_rotl},
		{"rotr", instruction_rotr},
		{NULL, NULL}
	};

	for (i = 0; all_ops[i].opcode; i++)
	{
		if (strcmp(op, all_ops[i].opcode) == 0)
		{
			all_ops[i].f(stack, line_number);
			return;
		}
	}
	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}