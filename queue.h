
#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include "list.h"
/* 

	Typical FIFO queue.
	The underlying implementation is a doubly linked list

	-- GB
*/

struct _queue {
	list lst_queue;
};

typedef struct _queue queue;

/* init queue - returns 0 on success, -1 on fail */
extern int queue_init(queue*);

/* gets front element of queue - returns NULL if queue is empty or on failure */
extern void* queue_front(const queue*);

/* gets back element of queue - return NULL if queue is empty or on failure */
extern void* queue_back(const queue*);

/* add element to the rear of the queue - returns 0 on sucess, -1 on failure */
extern int queue_push(queue*, const void* const);

/* removes and deletes element from the front of the queue - returns 0 on
   success, -1 on failure */
extern void queue_pop(queue*);

/* checks if the queue is empty - returns 0 if empty, 1 not empty */
extern int queue_is_empty(queue*);

/* returns the size of the queue, 0 if empty */
extern size_t queue_size(const queue*);


//////

extern void dbg_print_queue(queue*);

#endif
