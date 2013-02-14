
#include "debug.h"


void dbg_print_float_list(list* head)
{
	list* temp = head->next;
	int counter = 0;

	for (;;) {
		printf("dbg_print [%i]: %f\n", counter, (*(float*)temp->data));
		if (temp->next == NULL) break;
		temp = temp->next;
		counter++;
	}
}

void print_debug_float(list* lst, int pos)
{
	float* v = (float*)get_at(lst,pos);
	if (v == NULL)
		printf("FAIL\n");
	else
		printf(">> %f\n", *v);
}