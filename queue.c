
#include "queue.h"

int queue_init(queue* q) {
	list lst;
	if (init_list(&lst) == 1) {
		return 1;
	}
	else {
		q->lst_queue = lst;
		return 0;
	}
	
}

void* queue_front(queue* q) {
	get_front(&q->lst_queue);
}

void* queue_back(queue* q) {
	get_rear(&q->lst_queue);
}

int queue_push(queue* q, void* data) {
	return push_back(&q->lst_queue, data);
	
}

void queue_pop(queue* q) {
	get_front(&q->lst_queue);
	erase(&q->lst_queue, begin(&q->lst_queue));
}

int is_queue_empty(queue* q) {
	if (empty(&q->lst_queue)) {
		return 1;
	}
	else {
		return 0;
	}
}

size_t queue_size(queue* q) {
	return q->lst_queue.size;
}

void dbg_print_queue(queue* q) {
	dbg_print_list(&q->lst_queue);
}
