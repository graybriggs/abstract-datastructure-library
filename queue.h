
#ifndef QUEUE_H
#define QUEUE_H

struct _queue {
	struct _queue* next;
	void* data;
};

typedef struct _queue queue;

extern void init_queue(queue*);
extern void front(queue*);
extern void back(queue*);
extern void push(queue*, void*);
extern void pop(queue*);
extern void empty(queue*);
extern void size(queue*);

#endif