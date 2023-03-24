#include "monty.h"

/**
 * _mod - remainder of division of top 2 nodes of the stack
 * @stack: pointer to pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void _mod(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	if (tmp == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	_pop(stack, line_number);
	(*stack)->n %= tmp;
}
/**
 * _pchar - prints the char at the top of the stack
 * @stack: pointer to pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void _pchar(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	if (!(tmp >= 0 && tmp <= 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(tmp);
	putchar('\n');
}
