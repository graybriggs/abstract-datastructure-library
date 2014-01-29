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
extern iterator list_begin(const list*);
extern iterator list_end(const list*);
extern iterator list_next(iterator);
extern iterator list_advance(iterator, const int); // list, iterator, distance to iterate
/* update to const void* */
extern int list_insert(list*, iterator, const void* const);
extern int list_push_back(list*, const void* const);
extern int list_push_front(list*, const void* const);
extern void* list_get(const iterator);
extern void* list_get_front(const list*); // returns data of first list element else null
extern void* list_get_rear(const list*);
extern iterator list_erase(list*, iterator);
extern iterator list_erase_between(list*, iterator, iterator); // think of a better name
extern void list_clear(list*);
extern int list_is_empty(const list*);
extern void list_delete(list*);
extern size_t list_size(const list*);

///////

extern void dbg_print_list(list*);

#endif // LIST_H
