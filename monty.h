#ifndef MONTY_H
#define MONTY_H

#define UNUSED(x) (void)(x)
#define INSTRUCTIONS_COUNT 17
#define _GNU_SOURCE


#define STACK 1
#define QUEUE 0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln);
} instruction_t;

/**
 * data structure
 */
typedef struct data_s
{
	int ln;
	char *l;
	char *arg1;
	char *arg2;
	stack_t *stack;
	FILE *file;
	int data_mode;
} data_t;
extern data_t data;


/*error functions*/
void open_file_error(char *fn);


/*instructions struct...*/
void pall(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int ln);
void the_div(stack_t **stack, unsigned int ln);
void mul(stack_t **stack, unsigned int ln);
void mod(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void push(stack_t **stack, unsigned int ln);
void pint(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int ln);
void sub(stack_t **stack, unsigned int ln);
void pchar(stack_t **stack, unsigned int ln);
void pstr(stack_t **stack, unsigned int ln);
void queue(stack_t **stack, unsigned int ln);
void stack(stack_t **stack, unsigned int ln);
void rotl(stack_t **stack, unsigned int ln);
void rotr(stack_t **stack, unsigned int ln);


/*linked-list functions*/
size_t print_stack(const stack_t *h);
stack_t *add_node(stack_t **hd, const int n);
stack_t *add_stackint_end(stack_t **hd, const int n);
void free_stack(stack_t *hd);
void delete_top(stack_t **stack);


/*deletes everything*/
void free_all();


void pusage();
void pinvalid_instruction(int ln, char *opcode_instruction);
void pmalloc_error();
void ppush_error(int ln);
void pempty_stack(int ln);
void ppint(int ln);
void pswap(int ln);
void padd(int ln);
void psub(int ln);

void pdiv(int ln);
void pdiv_zero(int ln);

void pmul(int ln);
void pmod(int ln);

void pchar(int ln);
void pchar_stack_empty(int ln);


/*execute functions*/
int execf(char *fn);
void execl(char *l, int ln);

/*verifying*/
int is_emptyl(char *l);
int is_num(char *num);


#endif /*MONTY_H*/
