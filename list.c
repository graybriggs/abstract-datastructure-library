

#include "list.h"

int init_list(list* lst)
{
  assert(lst->head != NULL);
  
  lst->head = malloc(sizeof(struct _node));
  if (lst->head == NULL) {
    fprintf(stderr, "error malloc head\n");
    return 1;
  }

  lst->tail = malloc(sizeof(struct _node));
  if (lst->tail == NULL) {
    fprintf(stderr, "error malloc tail\n");
    return 1;
  }
  
  lst->head->next = lst->tail;
  lst->head->previous = NULL;
  lst->tail->next = NULL;
  lst->tail->previous = lst->head;
  lst->size = 0;

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
	struct _node* temp = malloc(sizeof(struct _node));
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
  
  assert (lst->head != NULL);
  
  node* n = malloc(sizeof(struct _node));
  if (n == NULL) {
	  return 1;  // fail
  }
  
  if (empty(lst)) {
  }
  else {
	n->previous = lst->tail->previous;
	n->next = lst->tail;
	lst->tail->previous = n;
	n->data = data;
	
	++lst->size;
	
	return 0;  // success
  }
}

int push_front(list* lst, void* data)
{
  assert (lst->head != NULL); 
  assert (data != NULL);

  // create the new node
  struct _node* temp = malloc(sizeof(struct _node));
  
  if (temp == NULL) {
	  return 1;
  }
  
  // point the data pointer at the data
  temp->data = data;

  // if the list is empty
  if (empty(lst)) {
	  lst->head->next = temp;
	  temp->next = lst->tail;
	  lst->tail->previous = temp;
	  temp->previous = lst->head;
	  ++lst->size;
	  return 0; // success
  }
  else {
	lst->head->next->previous = temp;
    temp->next = lst->head->next;
    temp->previous = lst->head;
    ++lst->size;
    return 0; // success
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
	node* n = lst->head->next;
	return n->data;
  }
  else {
    return NULL;
  }
}

void* get_rear(list* lst)
{
  if (!empty(lst)) {
    node* n = lst->tail->previous;
    return n->data;
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
