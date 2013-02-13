
#include <stdio.h>

#include "list.h"

void print_debug_float(list* lst, int pos)
{
	float* v = (float*)get_at(lst,pos);
	if (v == NULL)
		printf("FAIL\n");
	else
		printf(">> %f\n", *v);
}

int main()
{
	list* lst = init_list();
	float* v;
	float* f;
	
	f = (float*)malloc(sizeof(float));	
	*f = 1.11f;
	insert_front(lst, f);

	f = (float*)malloc(sizeof(float));
	*f = 2.22f;
	insert_front(lst, f);


	f = (float*)malloc(sizeof(float));
	*f = 3.33f;
	insert_front(lst, f);

	f = (float*)malloc(sizeof(float));
	*f = 4.44f;
	insert_front(lst, f);

	f = (float*)malloc(sizeof(float));
	*f = 5.55f;
	insert_front(lst, f);

	delete_at(lst, 3);

	print_debug_float(lst,0);
	print_debug_float(lst,1);
	print_debug_float(lst,2);
	print_debug_float(lst,3);
	print_debug_float(lst,4);

	getch();

	return 0;
}