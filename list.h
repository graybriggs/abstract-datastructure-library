#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct _list_s {
  struct _list_s* next;
  void* data;
  size_t size;
};

typedef struct _list_s list_s;


/* creates a head for the list and returns a pointer to its location */

extern int init_list_s(list_s*);

/* insert_rear - insert data at the rear of the list */

extern void insert_rear_s(list_s*, void* data);

/* insert_front - insert data at the front of the list */

extern void insert_front_s(list_s*, void* data);

/* insert_at - insert data at pos position */

extern void insert_at_s(list_s*, void* data, int pos);

/* get_at - return NULL on empty list else return data at pos */

extern void* get_at_s(list_s*, int pos);

extern void* get_front_s(list_s*);
extern void* get_back_s(list_s*);


/* delete_at - deletes element in list at position pos
   returns 0 on deletion success, -1 on out of list size range (ie. fail)
 */

extern int delete_at(list_s*, int pos);

/* is_empty - returns 1 if empty 0 othewise */

extern int is_empty_s(list_s*);

/* size - returns size of current list */

extern size_t size_s(list_s*);

/* deletes entire list and its contents */

extern void delete_list_s(list_s*);

////////////////////////
/* Doubly linked list */
///////////////////////

struct _node {
  struct _node next;
  struct _node previous;
};

struct _list_d {
  struct _node head;
  struct _node tail;
  //struct _list_d* head;
  //struct _list_d* tail;
  void* data;
  size_t size;
};

typedef struct _list_d list_d;

/* init_list_d - initialises head and tail nodes for doubly linked list. Returns -1 on failure, 1 on sucess */
extern int init_list_d(list_d*);

/* insert_front_d - inserts a node at the front of the list. Returns 1 on success, -1 on failure. */
extern int insert_front_d(list_d*, void*);

/* insert_rear_d - inserts a node at the rear of the list. Returns 1 on success, -1 on failure. */
extern int insert_rear_d(list_d*, void*);

/* insert_at_d - O(n) - inserts data at pos position. Returns 1 on success, -1 on failure */
extern int insert_at_d(list_d*, void* data, int pos);

extern void* get_front_d(list_d*);
extern void* get_back_d(list_d*);

/* delete_at_d - O(n) - deletes element in list at pos position. Returns 1 on success, -1 on failure */
extern int delete_at_d(list_d*, int pos);

/* is_empty_d -  returns 1 if the list is empty, 0 if not */
extern int is_empty_d(list_d*);

/* returns the amount of nodes created in the list - the size. Returns -1 if there was an inconsistency found */
extern size_t size_d(list_d*);


extern int delete_list_d(list_d*);


#endif // LIST_H
