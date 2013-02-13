
#include "stack.h"


stack* init_stack()
{
	stack* s;
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
	return s;
}

void push(stack* s, void* data)
{
	if (!s->top) {
		stack* temp_data = (stack*)malloc(sizeof(stack));
		temp_data->top->data = data;
		temp_data->size++;
	}

}

void print_stack(stack* s)
{

}