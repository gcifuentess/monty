#include "monty.h"

/*Global Variables definition*/
data_t *program_data = NULL;

/**
 * main - Monty Code Interpreter
 * @argc: number of arguments the program receives
 * @argv: array with the received arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	if (argc > 2 || argc <= 1)
		print_error(BAD_ARG, BAD_ARG);

	initialize();

	program_data->av_1 = argv[1];

	open_file();

	read_line();

	free_all(FREE_ALL);

	return (EXIT_SUCCESS);
}
