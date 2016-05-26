
#include "queue.h"

#include "error.h"

err_code queue_init(queue* q) {
	list lst;
	if (list_init(&lst) == 1) {
		return 1;
	}
	else {
		q->lst_queue = lst;
		return 0;
	}
	
}

void* queue_front(const queue* q) {
	return list_get_front(&q->lst_queue);
}

void* queue_back(const queue* q) {
	return list_get_rear(&q->lst_queue);
}

err_code queue_push(queue* q, const void* const data) {
	return list_push_back(&q->lst_queue, data);
	
}

void queue_pop(queue* q) {
	list_get_front(&q->lst_queue);
	list_erase(&q->lst_queue, list_begin(&q->lst_queue));
}

int queue_is_empty(queue* q) {
	if (list_is_empty(&q->lst_queue)) {
		return 1;
	}
	else {
		return 0;
	}
}

size_t queue_size(const queue* const q) {
	return q->lst_queue.size;
}

void dbg_print_queue(queue*q) {
	dbg_print_list(&q->lst_queue);
}
