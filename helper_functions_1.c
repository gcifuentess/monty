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
			opcodes[i].f(&(program_data->stack), line_number);
			if (check_malloc == GOOD_MALLOC)
				return (EXIT_SUCCESS);
			else
				return (print_error(program_data, BAD_MALLOC));
		}
	}
	return (print_error(program_data, ERROR_OPCODE));
}
