#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		check_malloc = BAD_MALLOC;
	new->n = line_number;
	new->prev = NULL;
	if (!(*stack))
	{
		new->next = NULL;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * pall - prints all the values on the stack
 *        , starting from the top of the stack.
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current;

	if (!stack)
		return;
	for (current = *stack; current; current = current->next)
		printf("%d\n", current->n);
}

/**
 * pint - prints the value at the top of the stack
 *         , followed by a new line.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void pop(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
/**
 * swap - swaps the top two elements of the stack.
 *
 * @stack: the double linked list with the stack
 * @line_number: the integer to be added to the stack
 *
 * Return: Void
 */
void swap(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	unsigned int temp;

	temp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = temp;
}
