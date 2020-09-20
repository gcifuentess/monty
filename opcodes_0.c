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
	char *arg;
	int i, num;
	const char *integers = "0123456789";

	arg = strtok(NULL, " \t");
	if (arg && arg[0] != '\n')
	{
		for (i = 0; arg[i] && arg[i] != '\n'; i++)
		{
			if (i == 0 && arg[i] == '-')
				continue;
			if (!(strchr(integers, arg[i])))
				print_error(ERROR_PUSH, line_number);
		}
	}
	else
	{
		print_error(ERROR_PUSH, line_number);
	}
	num = atoi(arg);

	new = malloc(sizeof(stack_t));
	if (!new)
		print_error(BAD_MALLOC, line_number);
	new->n = num;
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
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
		print_error(ERROR_PINT, line_number);

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
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack))
		print_error(ERROR_POP, line_number);

	temp = (*stack)->next;
	if (temp)
		temp->prev = NULL;
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
void swap(stack_t **stack, unsigned int line_number)
{
	unsigned int temp;

	if (!(*stack) && !(*stack)->next)
		print_error(ERROR_SWAP, line_number);

	temp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = temp;
}
