#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdint.h>

#define S_STACK_DEFAULT 10



typedef struct _stack {
	struct _stack next;
	void* data;
	size_t size;
} stack;


extern stack* init_stack();
extern int push(stack*, void*);
extern void pop(stack*);
extern void* top(stack*);
extern void delete_stack(stack*);

extern void print_stack(stack*);

#endif // STACK_H