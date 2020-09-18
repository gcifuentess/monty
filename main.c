#include "monty.h"

/**
 * main - Interpreter for Monty code
 * @argc: number of arguments the program receives
 * @argv: array with the received arguments
 *
 * Return: EXIT_SUCCES or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	data_t *program_data;

	program_data = NULL;

	if (argc > 2 || argc <= 1)
		exit(print_error(program_data, BAD_ARG));

	if (initialize(&program_data) == EXIT_FAILURE)
		exit(EXIT_FAILURE);

	program_data->av_1 = argv[1];
	if (open_file(program_data) ==  EXIT_FAILURE)
		exit(EXIT_FAILURE);

	if (read_line(program_data) == EXIT_FAILURE)
		exit(EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
