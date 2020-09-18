#include "monty.h"

/**
 * opcode_exec - executes the opcode
 * @program_data: structure with the data of the program
 * @opcodes: array with the opcodes function pointers
 *
 * Return: EXIT_SUCCESS the file was openned EXIT_FAILURE otherwise
 */
int opcode_exec(data_t *program_data, instruction_t opcodes[])
{
	int i;
	unsigned int line_number;

	line_number = 0;
	if (program_data->opc_arg)
		line_number = atoi(program_data->opc_arg);

	/*checks and runs if is an opcode that needs arguments*/
	for (i = 0; opcodes[i].opcode; i++)
	{
		/*compares the readed opcode with those in opcodes structure*/
		if (strcmp(program_data->opcode, opcodes[i].opcode) == 0)
		{
			if (strcmp(program_data->opcode, "push") == 0
			    && program_data->check_arg == BAD_ARG)
				return (print_error(program_data, ERROR_PUSH));

			if (strcmp(program_data->opcode, "pint") == 0
			    && !(program_data->stack))
				return (print_error(program_data, ERROR_PINT));

			/*excecute the opcode*/
			opcodes[i].f(&(program_data->stack), line_number);

			/*free the readed line*/
			free_all(program_data, FREE_LINE);

			/*check if there were errors with malloc*/
			if (check_malloc == GOOD_MALLOC)
				return (EXIT_SUCCESS);
			else
				return (print_error(program_data, BAD_MALLOC));
		}
	}

	return (print_error(program_data, ERROR_OPCODE));
}

/**
 * opcode_exec - executes the opcode
 * @program_data: structure with the data of the program
 * @free_case: int number with the case to free
 *
 * Return: void
 */
void free_all(data_t *program_data, int free_case)
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
