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

	if (!(*stack) || !((*stack)->next))
		print_error(ERROR_ADD, line_number);

	temp = (*stack)->n + ((*stack)->next)->n;
	((*stack)->next)->n = temp;
	pop(stack, line_number);
}

/**
 * nop - doesn’t do anything.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void nop(__attribute__((unused))stack_t **stack
	  , __attribute__((unused)) unsigned int line_number)
{
}

/**
 * sub - subtracts the top element of the stack
 *       from the second top element of the stack.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	unsigned int temp;

	if (!(*stack) || !((*stack)->next))
		print_error(ERROR_SUB, line_number);

	temp = ((*stack)->next)->n - (*stack)->n;
	((*stack)->next)->n = temp;
	pop(stack, line_number);
}

/**
 * div - divides the second top element of the stack
 *       by the top element of the stack.stack.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void div_m(stack_t **stack, unsigned int line_number)
{
	unsigned int temp;

	if (!(*stack) || !((*stack)->next))
		print_error(ERROR_DIV, line_number);

	if ((*stack)->n == 0)
		print_error(ERROR_DIVCERO, line_number);

	temp = ((*stack)->next)->n / (*stack)->n;
	((*stack)->next)->n = temp;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack
 *       with the top element of the stack.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	unsigned int temp;

	if (!(*stack) || !((*stack)->next))
		print_error(ERROR_MUL, line_number);

	temp = ((*stack)->next)->n * (*stack)->n;
	((*stack)->next)->n = temp;
	pop(stack, line_number);
}
