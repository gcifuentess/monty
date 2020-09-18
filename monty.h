#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*-----MACROS-----*/

#define BAD_MALLOC 1
#define BAD_ARG 2
#define ERROR_FILE 3
#define ERROR_OPCODE 4
#define ERROR_PUSH 5

#define STACK_M 0
#define QUEUE_M 1

#define GOOD_MALLOC 0
#define GOOD_ARG 0

#define FREE_ALL 0
#define FREE_LINE 1
#define FREE_PROGRAM_DATA 2

/*----------------*/

/*-----GLOBAL_VARS-----*/

extern int data_format;
extern int check_malloc;

/*----------------*/

/*-----STRUCTURES-----*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - structure to manage the data in the program
 * @count: keeps count of the number of lines readed
 * @av_1: keeps the name of the file to be interpreted
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct data_s
{
	int count;
	char *av_1;
	FILE *stream;
        char *line;
        char **tokens;
	char *opcode;
	char *opc_arg;
	int check_arg;
	stack_t *stack;

} data_t;

/*----------------*/

/*-----FUNCTIONS-----*/

int initialize(data_t **program_data);
int print_error(data_t *program_data, int n_error);
int open_file(data_t *program_data);
int read_line(data_t *program_data);
int check_to_exec(data_t *program_data);
int opcode_exec(data_t *program_data, instruction_t opcodes[]);
void free_all(data_t *program_data, int free_case);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/*----------------*/


#endif /*MONTY_H*/
