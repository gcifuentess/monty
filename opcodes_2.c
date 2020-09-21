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

/**
 * pstr - prints the string starting at the top of the stack
 *        , followed by a new line.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	for (current = *stack; current; current = current->next)
	{
		if (current->n < 1 || current->n > 127)
		{
			printf("\n");
			return;
		}
		printf("%c", current->n);
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;
	int num;

	if (!(*stack) || !((*stack)->next))
		return;

	num = (*stack)->n;

	for (current = (*stack)->next; current->next; current = current->next)
		(current->prev)->n = current->n;

	(current->prev)->n = current->n;

	current->n = num;
}

/**
 * rotr - rotates the stack to the bottom.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;
	int num_h, num_act, num_prev;

	if (!(*stack) || !((*stack)->next))
		return;

	num_h = (*stack)->n;
	num_prev = num_h;

	for (current = (*stack)->next; current; current = current->next)
	{
		num_act = current->n;
		current->n = num_prev;
		num_prev = num_act;
	}

	(*stack)->n = num_prev;
}
