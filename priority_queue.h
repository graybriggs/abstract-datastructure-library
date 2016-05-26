#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "error.h"

// subject to change.

struct _priority_queue {

};

typedef _priority_queue pq;

error_t pq_create(pq*);
error_t pq_insert(pq*, void* data);
void* pq_top(pq*);
void* remove_top(pq*);

#endif
