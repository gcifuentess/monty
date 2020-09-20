#include "monty.h"

/**
 * opcode_exec - executes the opcode
 * @opcodes: array with the opcodes function pointers
 *
 * Return: Void
 */
void opcode_exec(instruction_t opcodes[])
{
	int i;
	unsigned int line_number;

	line_number = program_data->count;
	/*checks and runs the opcode*/
	for (i = 0; opcodes[i].opcode; i++)
	{
                /*checks if opcode[] is a comment*/
		if (program_data->opcode[0] == '#')
		{
			/*opcode[6] is the nop opcode function*/
			opcodes[6].f(&(program_data->stack), line_number);
			return;
		}
		/*compares the readed opcode with those in opcodes structure*/
                /*or if opcode[] is a comment*/
		if (strcmp(program_data->opcode, opcodes[i].opcode) == 0)
		{
			/*excecute the opcode*/
			opcodes[i].f(&(program_data->stack), line_number);
			return;
		}
	}
	print_error(ERROR_OPCODE, line_number);
}

/**
 * free_all - executes the opcode
 * @free_case: int number with the case to free
 *
 * Return: void
 */
void free_all(int free_case)
{
	stack_t *head, *next;

	head = program_data->stack;

	if (free_case == FREE_ALL)
	{
		/*free stack*/
		while (head)
		{
			next = head->next;
			free(head);
			head = next;
		}

		/*free line*/
		free(program_data->line);

		/*close file*/
		fclose(program_data->stream);

		/*free program_data*/
		free(program_data);
	}
	else if (free_case == FREE_LINE)
	{
		/*free line*/
		free(program_data->line);

	}
	else if (free_case == FREE_PROGRAM_DATA)
	{
		free(program_data);
	}
}
/**
 * print_error_a - prints error messages
 * @n_error: int error code
 * @line_number: the number of the line where the error took place
 *
 * Return: ERROR_FOUND or ERROR_NOT_FOUND
 */
int print_error_a(int n_error, unsigned int line_number)
{
	if (n_error == BAD_MALLOC && !program_data)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (n_error == BAD_ARG)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_all(FREE_PROGRAM_DATA);
	}
	else if (n_error == ERROR_FILE)
	{
		fprintf(stderr, "Error: Can't open file %s\n"
			, program_data->av_1);
		free_all(FREE_PROGRAM_DATA);
	}
	else if (n_error == ERROR_OPCODE)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n"
			, program_data->count, program_data->opcode);
		free_all(FREE_ALL);
	}
	else if (n_error == ERROR_PUSH)
	{
		fprintf(stderr, "L%d: usage: push integer\n"
			, line_number);
		free_all(FREE_ALL);
	}
	else if (n_error == ERROR_PINT)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n"
			, line_number);
		free_all(FREE_ALL);
	}
	else
	{
		return (ERROR_NOT_FOUND);
	}

	return (ERROR_FOUND);
}

/**
 * print_error_b - prints error messages for the rest of opcodes
 * @n_error: int error code
 * @line_number: the number of the line where the error took place
 *
 * Return: ERROR_FOUND or ERROR_NOT_FOUND
 */
int print_error_b(int n_error, unsigned int line_number)
{

	if (n_error == ERROR_POP)
		fprintf(stderr, "L%d: can't pop an empty stack\n"
			, line_number);

	else if (n_error == ERROR_SWAP)
		fprintf(stderr, "L%d: can't swap, stack too short\n"
			, line_number);

	else if (n_error == ERROR_ADD)
		fprintf(stderr, "L%d: can't add, stack too short\n"
			, line_number);

	else if (n_error == ERROR_SUB)
		fprintf(stderr, "L%d: can't sub, stack too short\n"
			, line_number);

	else if (n_error == ERROR_DIV)
		fprintf(stderr, "L%d: can't div, stack too short\n"
			, line_number);

	else if (n_error == ERROR_DIVCERO)
		fprintf(stderr, "L%d: division by zero\n"
			, line_number);

	else if (n_error == ERROR_MUL)
		fprintf(stderr, "L%d: can't mul, stack too short\n"
			, line_number);

	else if (n_error == ERROR_MOD)
		fprintf(stderr, "L%d: can't mod, stack too short\n"
			, line_number);
	else
		return (ERROR_NOT_FOUND);

	free_all(FREE_ALL);

	return (ERROR_FOUND);
}

/**
 * print_error_c - prints error messages for the rest of opcodes
 * @n_error: int error code
 * @line_number: the number of the line where the error took place
 *
 * Return: ERROR_FOUND or ERROR_NOT_FOUND
 */
int print_error_c(int n_error, unsigned int line_number)
{

	if (n_error == ERROR_PCHAR_STACK)
		fprintf(stderr, "L%d: can't pchar, stack empty\n"
			, line_number);

	else if (n_error == ERROR_PCHAR_RANGE)
		fprintf(stderr, "L%d: can't pchar, value out of range\n"
			, line_number);
	else
		return (ERROR_NOT_FOUND);

	free_all(FREE_ALL);

	return (ERROR_FOUND);
}
