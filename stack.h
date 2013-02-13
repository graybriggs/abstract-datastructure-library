#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#define S_STACK_DEFAULT 10


typedef struct {
	void* data;
	void* next;
} node;

typedef struct {
	node* top;
	node* bottom;
	size_t size;
} stack;


extern stack* init_stack();
extern void push(stack*, void*);
extern void pop(stack*);
extern void* top(stack*);
extern void delete_stack(stack*);

extern void print_stack(stack*);

#endif // STACK_H