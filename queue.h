
#ifndef QUEUE_H
#define QUEUE_H

/* the underlying implementation is a doubly linked list */

struct _queue {
	struct _queue* next;
	void* data;
};

typedef struct _queue queue;

/* init queue - returns 0 on success, -1 on fail */
extern int init_queue(queue*);

/* gets front element of queue - returns NULL if queue is empty or on failure */
extern void* front(queue*);

/* gets back element of queue - return NULL if queue is empty or on failure */
extern void* back(queue*);

/* add element to the rear of the queue - returns 0 on sucess, -1 on failure */
extern int push(queue*, void*);

/* removes and deletes element from the front of the queue - returns 0 on
   success, -1 on failure */
extern int pop(queue*);

/* checks if the queue is empty - returns 0 if empty, 1 not empty */
extern int empty(queue*);

/* returns the size of the queue, 0 if empty */
extern size_t size(queue*);

#endif
