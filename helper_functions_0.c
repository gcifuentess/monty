#include "monty.h"

/**
 * initialize - initializes the data of the program
 *
 * Return: Void
 */
void initialize(void)
{
	program_data = malloc(sizeof(data_t));
	if (!program_data)
		print_error(BAD_MALLOC, BAD_MALLOC);

	/*initialize program_data*/
	program_data->count = 0;
	program_data->av_1 = NULL;
	program_data->stream = NULL;
	program_data->line = NULL;
	program_data->opcode = NULL;
	program_data->stack = NULL;
	program_data->data_format = STACK_M;
}

/**
 * print_error - prints error messages
 * @n_error: int error code
 * @line_number: the number of the line where the error took place
 *
 * Return: Void
 */
void print_error(int n_error, unsigned int line_number)
{

	if (print_error_a(n_error, line_number) == ERROR_FOUND)
		exit(EXIT_FAILURE);

	if (print_error_b(n_error, line_number) == ERROR_FOUND)
		exit(EXIT_FAILURE);

	if (print_error_c(n_error, line_number) == ERROR_FOUND)
		exit(EXIT_FAILURE);
}

/**
 * open_file - opens te file from argv[1]
 *
 * Return: Void
 */
void open_file(void)
{
	program_data->stream = fopen(program_data->av_1, "r");

	if (!(program_data->stream))
		print_error(ERROR_FILE, ERROR_FILE);
}

/**
 * read_line - opens te file from argv[1]
 *
 * Return: Void
 */
void read_line(void)
{
	size_t len;
	int retget;

	len = 0;
	retget = 0;

	while (retget != EOF)
	{
		program_data->count += 1;/*counting the number of lines*/
		/*read each line of the file*/
		retget = getline(&(program_data->line)
				 , &len, program_data->stream);
		if (retget == EOF)
			return;

		/*get the first token of the file to get the opcode*/
		program_data->opcode = strtok(program_data->line, " \t");
		/*check if the line is empty*/
		if (program_data->opcode[0] == '\n')
			continue;
		/*check if an opcode was readed*/
		check_to_exec();
	}
}

/**
 * check_to_exec - checks if the received line is ok to be executed
 *
 * Return: Void
 */
void check_to_exec(void)
{
	char *opcode_s;
	char end_opcode_s;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_m},
		{"mul", mul},
		{"mod", mod_m},
		{"pchar", pchar},
		{NULL, NULL}
	};

	/*check if the read opcode has new_line char*/
	opcode_s = program_data->opcode;
	end_opcode_s = opcode_s[strlen(opcode_s) - 1];
	if (end_opcode_s == '\n')
		opcode_s[strlen(opcode_s) - 1] = '\0';

	opcode_exec(opcodes);
}
