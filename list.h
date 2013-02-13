#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct _list {
	struct _list* next;
	void* data;
	size_t size;
};

typedef struct _list list;


/* creates a head for the list and returns a pointer to its location */

extern list* init_list();

/* insert_rear - insert data at the rear of the list */

extern void insert_rear(list*, void* data);

/* insert_front - insert data at the front of the list */

extern void insert_front(list*, void* data);

/* insert_at - insert data at pos position */

extern void insert_at(list*, void* data, int pos);

/* get_at - return NULL on empty list else return data at pos */

extern void* get_at(list*, int pos);

/* delete_at - deletes element in list at position pos
   returns 0 on deletion success, -1 on out of list size range (ie. fail)
 */

extern int delete_at(list*, int pos);

/* is_empty - returns 1 if empty 0 othewise */

extern int is_empty(list*);

/* size - returns size of current list */

extern size_t size(list*);

/* deletes entire list and its contents */

extern void delete_list(list*);




#endif // LIST_H