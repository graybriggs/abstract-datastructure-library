
#include <stdio.h>

#include "list.h"
#include "debug.h"



int main()
{
	list* lst = init_list();
	float* v;
	float* f;
	
	f = (float*)malloc(sizeof(float));	
	*f = 1.11f;
	insert_rear(lst, f);

	f = (float*)malloc(sizeof(float));
	*f = 2.22f;
	insert_rear(lst, f);


	f = (float*)malloc(sizeof(float));
	*f = 3.33f;
	insert_rear(lst, f);

	f = (float*)malloc(sizeof(float));
	*f = 4.44f;
	insert_rear(lst, f);

	f = (float*)malloc(sizeof(float));
	*f = 5.55f;
	insert_rear(lst, f);



	dbg_print_float_list(lst);

	printf("-----------------\n");

	f = (float*)malloc(sizeof(float));
	*f = 7.77f;
	insert_at(lst, f, 2);
	delete_at(lst, 2);
	f = (float*)malloc(sizeof(float));
	*f = 8.88f;
	insert_at(lst, f, 4);

	dbg_print_float_list(lst);

	delete_list(lst);

	getch();

	return 0;
}