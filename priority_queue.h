#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "error.h"

// subject to change.

struct _priority_queue {

};

typedef struct _priority_queue pq;

err_code pq_create(pq*);
void pq_delete(pq*);
err_code pq_insert(pq*, void* data);
void* pq_top(pq*);
void* remove_top(pq*);

#endif
