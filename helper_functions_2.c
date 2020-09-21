#include "monty.h"

/**
 * add_node - adds a double linked list to head
 *
 * Return: Void
 */
void add_node(int element)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		print_error(BAD_MALLOC, program_data->count);
	new->n = element;
	new->prev = NULL;
	if (!(program_data->stack))
	{
		new->next = NULL;
	}
	else
	{
		new->next = program_data->stack;
		(program_data->stack)->prev = new;
	}
	program_data->stack = new;
}

/**
 * add_node_end - adds a double linked list to head
 *
 * Return: Void
 */
void add_node_end(int element)
{
	stack_t *new, *actual;

	new = malloc(sizeof(stack_t));
	if (!new)
		print_error(BAD_MALLOC, program_data->count);
	new->n = element;
	new->next = NULL;
	if (!(program_data->stack))
	{
		new->prev = NULL;
		program_data->stack = new;
	}
	else
	{
		for (actual = program_data->stack; actual->next
			     ; actual = actual->next)
		{}
		new->prev = actual;
		actual->next = (program_data->stack)->prev = new;
	}
}
