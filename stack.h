#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define S_STACK_DEFAULT 10

typedef struct _stack {
	struct _stack* next;
	void* data;
	size_t size;

	struct _stack* top;

} stack;


extern int stack_init(stack*);
extern int stack_push(stack*, void*);
extern void stack_pop(stack*);
extern void* stack_top(stack*);
extern void stack_delete(stack*);

extern void print_stack(stack*);

#endif // STACK_H
