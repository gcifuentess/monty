#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----MACROS-----*/

#define BAD_MALLOC 1
#define BAD_ARG 2
#define ERROR_FILE 3
#define ERROR_OPCODE 4
#define ERROR_PUSH 5
#define ERROR_PINT 6
#define ERROR_POP 7
#define ERROR_SWAP 8
#define ERROR_ADD 9
#define ERROR_SUB 10
#define ERROR_DIV 11
#define ERROR_DIVCERO 12
#define ERROR_MUL 13
#define ERROR_MOD 14
#define ERROR_PCHAR_STACK 15
#define ERROR_PCHAR_RANGE 16

#define STACK_M 0
#define QUEUE_M 1

#define FREE_ALL 0
#define FREE_LINE 1
#define FREE_PROGRAM_DATA 2

#define ERROR_FOUND 0
#define ERROR_NOT_FOUND 1

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
 * @stream: keeps the file to be interpreted
 * @line: keeps the last readed line from @stream
 * @opcode: keeps first token from @line, usually the opcode
 * @stack: keeps the Data Structure (double linked list)
 * @data_format: keeps the data_format (Stack or Queue)
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
	char *opcode;
	stack_t *stack;
	int data_format;

} data_t;

/*----------------*/

/*-----FUNCTIONS-----*/

void initialize(void);
void print_error(int n_error, unsigned int line_number);
int print_error_a(int n_error, unsigned int line_number);
int print_error_b(int n_error, unsigned int line_number);
int print_error_c(int n_error, unsigned int line_number);
void open_file(void);
void read_line(void);
void check_to_exec(void);
void opcode_exec(instruction_t opcodes[]);
void free_all(int free_case);


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_m(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod_m(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void add_node(int element);
void add_node_end(int element);

/*----------------*/

/*-----GLOBAL_VARS-----*/

extern data_t *program_data;

/*----------------*/

#endif /*MONTY_H*/
