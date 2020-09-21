#include "monty.h"

/**
 * mod_m - Computes the rest of the division of the second top
 *       element of the stack by the top element of the stack.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void mod_m(stack_t **stack, unsigned int line_number)
{
	unsigned int temp;

	if (!(*stack) || !((*stack)->next))
		print_error(ERROR_MOD, line_number);

	if ((*stack)->n == 0)
		print_error(ERROR_DIVCERO, line_number);

	temp = ((*stack)->next)->n % (*stack)->n;
	((*stack)->next)->n = temp;
	pop(stack, line_number);
}

/**
 * pchar - computes the rest of the division of the second
 *         top element of the stack by the top element of the stack.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
		print_error(ERROR_PCHAR_STACK, line_number);

	if ((*stack)->n < 0 || (*stack)->n > 127)
		print_error(ERROR_PCHAR_RANGE, line_number);

	printf("%c\n", (*stack)->n);
}
