#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct _node {
  struct _node next;
  struct _node previous;
};

struct _list {
  struct _node head;
  struct _node tail;
  void* data;
  size_t size;
};

typedef struct _list list;

//////////// Iterator for list //////

typedef struct _list* iterator;

extern int init_list(list*);
extern iterator begin(list*);
extern iterator end(list*);
extern iterator next(list*, iterator);
extern void advance(list*, iterator, int); // list, iterator, distance to iterate
extern int insert(list*, iterator, void*);
extern void* get(list*, iterator);
extern void* get_front(list*);
extern void* get_rear(list*);
extern iterator erase(list*, iterator);
extern iterator erase_between(list*, iterator, iterator); // think of a better name
extern void clear(list*);
extern int empty(list*);
extern int delete_list(list*);
extern size_t size(list*);


#endif // LIST_H
