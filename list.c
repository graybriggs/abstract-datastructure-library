

#include "list.h"

int init_list(list* lst)
{
  assert(lst->head == NULL);
  
  lst->head = (struct _node*)malloc(sizeof(struct _node));
  if (lst->head == NULL) {
    fprintf(stderr, "error malloc head\n");
    return 1;
  }

  lst->tail = (struct _node*)malloc(sizeof(struct _node));
  if (lst->tail == NULL) {
    fprintf(stderr, "error malloc tail\n");
    return 1;
  }
  
  lst->head->next = lst->tail;
  lst->head->previous = NULL;
  lst->tail->next = NULL;
  lst->tail->previous = lst->head;

  return 0; // success
}

/* return an iterator to the first element of the list */

iterator begin(list* lst)
{
  assert(lst != NULL);

  iterator it;
  it = lst->head->next;
  return it;
}


/* return an iterator to one past the final element of the list */

iterator end(list* lst)
{
  assert(lst != NULL);

  iterator it;
  it = lst->tail;
  return it;
}

/* move iterator to the next element of the list */

iterator next(iterator it)
{
  //assert(it != NULL); // ?

  it = it->next;

  return it;
}


void advance(iterator it, int val)
{

}

int insert(list* lst, iterator it, void* data)
{
	struct _node* temp = (struct _node*)malloc(sizeof(struct _node));
	if (temp == NULL) {
		return 1;
	}
	else {
		temp->next = it->next;
		temp->previous = it->previous;
		it->previous->next = temp;
		it->next->previous = temp;
		temp->data = data;
		++lst->size;
		
		return 0;
	}
}

int push_back(list* lst, void* data)
{
  // could contain an internal iterator ??
}

int push_front(list* lst, void* data)
{
  assert (lst->head != NULL); 
  assert (data != NULL);

  // create the new node
  struct _node* temp = (struct _node*)malloc(sizeof(struct _node));
  // point the data pointer at the data
  temp->data = data;

  // if the list is empty
  if (empty(lst)) {
	  lst->head->next = temp;
	  temp->next = lst->tail;
	  temp->previous = lst->head;
	  ++lst->size;
  }
  else {
	lst->head->next->previous = temp;
    temp->next = lst->head->next;
    temp->previous = lst->head;
    ++lst->size;
  }

}

void* get(list* lst, iterator it)
{
}

/* 
 * Returns the data from the front element of the list.
 * Returns NULL if list is empty.
 */
void* get_front(list* lst)
{
  assert(lst->head != NULL);

  if (!empty(lst)) {
    if (lst->head != NULL) {
      return lst->head->next->data;
    }
    else {
      return NULL;
    }
  }
  else {
    return NULL;
  }
}

void* get_rear(list* lst)
{
  if (!empty(lst)) {
    
  }
  else {
    return NULL;
  }
}

iterator erase(list* lst, iterator it)
{
}

iterator erase_between(list* lst, iterator it1, iterator it2)
{
}

void clear(list* lst)
{
}

int empty(list* lst)
{
  assert(lst->head != NULL);

  if (lst->size == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

int delete_list(list* lst)
{

}

size_t size(list* lst)
{
  assert(lst != NULL);

  return lst->size;
}
