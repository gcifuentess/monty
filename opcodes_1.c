#include "monty.h"
/**
 * add - adds the top two elements of the stack
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void add(stack_t **stack, unsigned int line_number)
{
	unsigned int temp;

	if (!(*stack) && !(*stack)->next)
		print_error(ERROR_ADD, line_number);

	temp = (*stack)->n + ((*stack)->next)->n;
	((*stack)->next)->n = temp;
	pop(stack, line_number);
}
