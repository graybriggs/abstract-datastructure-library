#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct _link {
  struct _link link;
};

struct _list {
  struct _link next;
  struct _link previous;
  void* data;
  size_t size;
};

typedef struct _list list;

//////////// Iterator for list //////

typedef struct _list* iterator;

extern int init_list(list*);
extern iterator begin(list*);
extern iterator end(list*);
extern iterator next(iterator);
extern void advance(iterator, int); // list, iterator, distance to iterate
extern int insert(list*, iterator, void*);
extern int push_back(list*, void*);
extern int push_front(list*, void*);
extern void* get(list*, iterator);
extern void* get_front(list*); // returns data of first list element else null
extern void* get_rear(list*);
extern iterator erase(list*, iterator);
extern iterator erase_between(list*, iterator, iterator); // think of a better name
extern void clear(list*);
extern int empty(list*);
extern int delete_list(list*);
extern size_t size(list*);


#endif // LIST_H
