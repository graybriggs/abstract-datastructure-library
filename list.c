

#include "list.h"

int list_init(list* lst)
{
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

/* return an iterator to the first element of the list
 * 
 * Note: if the list is empty, begin() == end()
 * 
 */

iterator list_begin(list* lst)
{
  assert(lst->head != NULL);
  assert(lst->tail != NULL);

  iterator it;
  it = lst->head->next;
  return it;
}


/* return an iterator to one past the final element of the list */

iterator list_end(list* lst)
{
  assert(lst->head != NULL);
  assert(lst->tail != NULL);

  iterator it;
  it = lst->tail;
  return it;
}

/* move iterator to the next element of the list */

iterator list_next(iterator it)
{
  //assert(it != NULL); // ?

  it = it->next;

  return it;
}


/* advance the iterator by val amount */
iterator list_advance(iterator it, int val)
{
	for (int i = 0; i < val; ++i) {
		it = it->next;
	}
	return it;
}

int list_insert(list* lst, iterator it, void* data)
{
	assert(lst->head != NULL);
	assert(lst->tail != NULL);
	
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

int list_push_back(list* lst, void* data)
{
  // could contain an internal iterator ??
  
  assert(lst->head != NULL);
  assert(lst->tail != NULL);
  assert (data != NULL);
  
  node* n = malloc(sizeof(struct _node));
  if (n == NULL) {
	  return 1;  // fail
  }
  else {
	  n->data = data;
  }
  
  if (list_is_empty(lst)) {
	  lst->head->next = n;
	  lst->tail->previous = n;
	  n->previous = lst->head;
	  n->next = lst->tail;
	  
	  ++lst->size;
	  
	  return 0;
  }
  else {
	n->previous = lst->tail->previous;
	lst->tail->previous->next = n;
	n->next = lst->tail;
	lst->tail->previous = n;
	
	++lst->size;
	
	return 0;  // success
  }
}

int list_push_front(list* lst, void* data)
{
  assert(lst->head != NULL);
  assert(lst->tail != NULL);; 
  assert (data != NULL);

  // create the new node
  struct _node* temp = malloc(sizeof(struct _node));
  
  if (temp == NULL) {
	  return 1;  // fail
  }
  else {
	// point the data pointer at the data
	temp->data = data;
  }
  // if the list is empty
  if (list_is_empty(lst)) {
	  lst->head->next = temp;
	  temp->next = lst->tail;
	  lst->tail->previous = temp;
	  temp->previous = lst->head;
	  ++lst->size;
	  return 0; // success
  }
  else {
	node* t = lst->head->next;
	t->previous = temp;
    temp->next = t;
    temp->previous = lst->head;
    lst->head->next = temp;
    ++lst->size;
    return 0; // success
  }

}

void* list_get(iterator it)
{
	return it->data;
}

/*
void* get(list* lst, iterator it)
{
	return it->data;
}
*/

/* 
 * Returns the data from the front element of the list.
 * Returns NULL if list is empty.
 */
void* list_get_front(list* lst)
{
  assert(lst->head != NULL);
  assert(lst->tail != NULL);

  if (!list_is_empty(lst)) {
	node* n = lst->head->next;
	return n->data;
  }
  else {
    return NULL;
  }
}

void* list_get_rear(list* lst)
{
  assert(lst->head != NULL);
  assert(lst->tail != NULL);
	
  if (!list_is_empty(lst)) {
    node* n = lst->tail->previous;
    return n->data;
  }
  else {
    return NULL;
  }
}

/* deletes element specified by the iterator
 * returns an iterator to the next element to the deleted
 * returns iterator to end() if the element deleted was the last
 */
iterator list_erase(list* lst, iterator it)
{
	assert(lst->head != NULL);
	assert(lst->tail != NULL);
	
	iterator new_it = list_next(it);
	
	struct _node* prev = it->previous;
	struct _node* nxt = it->next;
	prev->next = nxt;
	nxt->previous = prev;
	
	free(it->data);
	free(it);
	
	--lst->size;
	
	return new_it;
}

iterator list_erase_between(list* lst, iterator it1, iterator it2)
{
	assert(lst->head != NULL);
	assert(lst->tail != NULL);
	
	iterator it = it1;
	
	while (it != it2) {
		it = list_erase(lst, it);
	}
	return it;
}

/* clears and deletes all elements that the list holds
 * leaving the list with a size of 0
 */

void list_clear(list* lst)
{
	assert(lst->head != NULL);
	assert(lst->tail != NULL);
	
	list_erase_between(lst, list_begin(lst), list_end(lst));
}


/* returns 1 if the list is empty
 * returns 0 if the list is not empty
 */

int list_is_empty(list* lst)
{
  assert(lst->head != NULL);
  assert(lst->tail != NULL);

  if (lst->size == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

void list_delete(list* lst)
{
	assert(lst->head != NULL);
	assert(lst->tail != NULL);
	
	list_erase_between(lst, list_begin(lst), list_end(lst));
	
	free(lst->head);
	free(lst->tail);
	lst->head = NULL;
	lst->tail = NULL;
}

size_t list_size(list* lst)
{
  assert(lst->head != NULL);
  assert(lst->tail != NULL);

  return lst->size;
}


/////

void dbg_print_list(list* lst) {

	printf("List Dump\n");
	
	if (lst->head == NULL || lst->tail == NULL) {
		printf("No list found.\n");
	}
	else if (list_is_empty(lst)) {
		printf("List is empty.\n");
	}
	else{
		for (iterator it = list_begin(lst); it != list_end(lst); it = list_next(it)) {
			printf("%c\n", *(char*)list_get(it));
		}		
	}
}

