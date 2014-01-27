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

extern int init_list(list*);
extern iterator begin(list*);
extern iterator end(list*);
extern iterator next(iterator);
extern iterator advance(iterator, int); // list, iterator, distance to iterate
extern int insert(list*, iterator, void*);
extern int push_back(list*, void*);
extern int push_front(list*, void*);
extern void* get(iterator);
extern void* get_front(list*); // returns data of first list element else null
extern void* get_rear(list*);
extern iterator erase(list*, iterator);
extern iterator erase_between(list*, iterator, iterator); // think of a better name
extern void clear(list*);
extern int empty(list*);
extern void delete_list(list*);
extern size_t size(list*);

///////

extern void dbg_print_list(list*);

#endif // LIST_H
