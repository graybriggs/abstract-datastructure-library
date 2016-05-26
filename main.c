
#include <stdio.h>

#include "list.h"
#include "queue.h"
#include "stack.h"

void helper_push_queue(queue* que, char c) {
	char* mem;
	mem = malloc(sizeof(char));
	*mem = c;
	queue_push(que, mem);
}


int main()
{
	
	list lst;
	list_init(&lst);
	
	printf("size: %d\n", (int)list_size(&lst));
	
	char* c;
	
	c = malloc(sizeof(char));
	*c = 'y';
	list_push_front(&lst, c);

	c = malloc(sizeof(char));
	*c = 'a';
	list_push_front(&lst, c);
	
	c = malloc(sizeof(char));
	*c = 'r';
	list_push_front(&lst, c);
	
	c = malloc(sizeof(char));
	*c = 'g';
	list_push_front(&lst, c);
	
	//dbg_print_list(&lst);
	
	iterator it;
	it = list_begin(&lst);
	it = list_advance(it, 2);
	
	dbg_print_list(&lst);
	
	//it = list_erase_between(&lst, begin(&lst), it);
	list_clear(&lst);
	printf("size: %d\n", (int)list_size(&lst));
	
	dbg_print_list(&lst);
	
	char* chr = malloc(sizeof(char));
	*chr = 'x';
	list_push_front(&lst, chr);
	chr = malloc(sizeof(char));
	*chr = 'z';
	list_push_back(&lst, chr);
	printf("size: %d\n", (int)list_size(&lst));
	dbg_print_list(&lst);
	
	list_delete(&lst);
	
	dbg_print_list(&lst);
	
	////////////
	
	queue q;
	queue_init(&q);
	
	helper_push_queue(&q, 'd');
	helper_push_queue(&q, 'a');
	helper_push_queue(&q, 't');
	helper_push_queue(&q, 'a');
	
	printf("queue size: %d\n", (int)queue_size(&q));
	
	char* c1 = (char*)queue_front(&q);
	char* c2 = (char*)queue_back(&q);
	printf("%c, %c\n", *c1, *c2);
	
	dbg_print_queue(&q);
	
	return 0;
}
