
#include "stack.h"


err_code stack_init(stack* s)
{
	s = malloc(sizeof(struct _stack));
	if (s == NULL) {
		return ERR_FAILURE;
	}
	else {
		s->next = NULL;
		s->data = NULL;
		s->size = 0;
		s->top->next = s;
		return s;
	}
}

err_code stack_push(stack* s, void* data)
{
	struct _stack* n = malloc(sizeof(struct _stack));
	
	if (n == NULL) {
		return ERR_FAILURE; // error
	}
	else {
		n->next = NULL;
		n->data = data;
		
		if (s->size == 0) {
			s->top->next = n;
			s->next = n;
			temp_data->size++;
		}
		else {
			struct _stack* temp = s->top->next;
			temp->next = n;
			s->top->next = n;
			++s->size;
		}
	}
}

void stack_pop(stack* s) {
	/// uhhh
}

void* stack_top(stack* s) {
	return s->top->data;
}

void print_stack(stack* s)
{

}
