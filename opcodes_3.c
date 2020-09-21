#include "monty.h"

/**
 * stack - rotates the stack to the top.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void stack(__attribute__((unused))stack_t **stack,
	   __attribute__((unused)) unsigned int line_number)
{
	program_data->data_format = STACK_M;
}

/**
 * queue - rotates the stack to the top.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void queue(__attribute__((unused))stack_t **stack,
	   __attribute__((unused)) unsigned int line_number)
{
	program_data->data_format = QUEUE_M;
}
