#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// doubly linked list

// A list node. It points at the previous and next node
// and each node holds data
typedef struct _node {
  struct _node* next;
  struct _node* previous;
  void* data;
} node;

// The actual list. Consists of a head and tail node.
// The list knows where its head and tail are at all times
// The list holds its current size
typedef struct _list {
  struct _node* head;
  struct _node* tail;
  size_t size;
} list;

//typedef struct _list list;

//////////// Iterator for list //////

typedef struct _node* iterator;

extern int list_init(list*);
extern iterator list_begin(list*);
extern iterator list_end(list*);
extern iterator list_next(iterator);
extern iterator list_advance(iterator, int); // list, iterator, distance to iterate
extern int list_insert(list*, iterator, void*);
extern int list_push_back(list*, void*);
extern int list_push_front(list*, void*);
extern void* list_get(iterator);
extern void* list_get_front(list*); // returns data of first list element else null
extern void* list_get_rear(list*);
extern iterator list_erase(list*, iterator);
extern iterator list_erase_between(list*, iterator, iterator); // think of a better name
extern void list_clear(list*);
extern int list_is_empty(list*);
extern void list_delete(list*);
extern size_t list_size(list*);

///////

extern void dbg_print_list(list*);

#endif // LIST_H
