#include "monty.h"

/*definition of Global Variables*/
int data_format = 0;
int check_malloc = 0;

/**
 * initialize - initializes the data of the program
 * @program_data: the double pointer to the structure
 *
 * Return: the pointer to the now initialized structur
 */
int initialize(data_t **program_data)
{

	*program_data = malloc(sizeof(data_t));
	if (!program_data)
		return (print_error(*program_data, BAD_MALLOC));

	/*initialize program_data*/
	(*program_data)->count = 0;
	(*program_data)->av_1 = NULL;
	(*program_data)->stream = NULL;
	(*program_data)->line = NULL;
	(*program_data)->tokens = NULL;
	(*program_data)->opcode = NULL;
	(*program_data)->opc_arg = NULL;
	(*program_data)->check_arg = GOOD_ARG;
	(*program_data)->stack = NULL;

	/*initialize Global Variables*/
	data_format += STACK_M;
	check_malloc += GOOD_MALLOC;

	return (EXIT_SUCCESS);
}

/**
 * print_error - prints error messages
 * @program_data: structure with the data of the program
 *
 * Return: EXIT_FAILURE
 */
int print_error(data_t *program_data, int n_error)
{
	if (n_error == BAD_MALLOC && !program_data)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (n_error == BAD_ARG)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	else if (n_error == ERROR_FILE)
	{
		fprintf(stderr, "Error: Can't open file %s\n"
			, program_data->av_1);
	}
	else if (n_error == ERROR_OPCODE)
	{
		fprintf(stderr, "L%d: usage: unknown instruction %s\n"
			, program_data->count, program_data->opcode);
	}
	else if (n_error == ERROR_PUSH)
	{
		fprintf(stderr, "L%d: usage: push integer\n"
			, program_data->count);
	}
	else if (n_error == ERROR_PINT)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n"
			, program_data->count);
	}
	else if (n_error == ERROR_POP)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n"
			, program_data->count);
	}


	return (EXIT_FAILURE);
}

/**
 * open_file - opens te file from argv[1]
 * @program_data: structure with the data of the program
 *
 * Return: EXIT_SUCCESS the file was openned EXIT_FAILURE otherwise
 */
int open_file(data_t *program_data)
{
	program_data->stream = fopen(program_data->av_1, "r");

	if (!(program_data->stream))
	{
		print_error(program_data, ERROR_FILE);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/**
 * read_line - opens te file from argv[1]
 * @program_data: structure with the data of the program
 *
 * Return: EXIT_SUCCESS the file was openned EXIT_FAILURE otherwise
 */
int read_line(data_t *program_data)
{
	char *line;
	size_t len;
	char *tokens[2] = {NULL, NULL};
	int i, retget, exit_c;

	line = NULL;
	len = 0;
	retget = 0;
	exit_c = EXIT_SUCCESS;

	while (retget != EOF)
	{
		program_data->count += 1;/*counting the number of lines*/
		retget = getline(&line, &len, program_data->stream);
		program_data->line = line;
		if (retget == EOF)
			return (EXIT_SUCCESS);

		for (i = 0; i < 2; i++, line = NULL)
		{
			tokens[i] = strtok(line, " ");
			if (!tokens[i])
				break;
		}
		program_data->tokens = tokens;
		program_data->opcode = tokens[0];
		program_data->opc_arg = tokens[1];

		exit_c = check_to_exec(program_data);
		if (exit_c == EXIT_FAILURE)
			return (exit_c);
	}

	return (exit_c);
}

/**
 * check_to_exec - checks if the received line is ok to be executed
 * @program_data: structure with the data of the program
 *
 * Return: EXIT_SUCCESS the file was openned EXIT_FAILURE otherwise
 */
int check_to_exec(data_t *program_data)
{
	int i;
	char *arg, *opcode_s;
	char end_opcode_s;
	const char *numbers = "0123456789";

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	/*check if the read opecode has new_line char*/
	opcode_s = program_data->opcode;
	end_opcode_s = opcode_s[strlen(opcode_s) - 1];
	if (end_opcode_s == '\n')
		opcode_s[strlen(opcode_s) - 1] = '\0';

	/*check if the argument is just numbers or NULL*/
	program_data->check_arg = GOOD_ARG;
	arg = program_data->opc_arg;
	if (arg)
	{
		for (i = 0; arg[i]; i++)
		{
			if (strchr(numbers, arg[i]))
				break;
		}
		if (arg[i] == '\n')
			program_data->check_arg = BAD_ARG;
	}
	else
	{
		program_data->check_arg = BAD_ARG;
	}

	return (opcode_exec(program_data, opcodes));
}
