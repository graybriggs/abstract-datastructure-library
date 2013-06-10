

#include "list.h"

int init_list(list* list)
{
  assert(list == NULL);
  
  list* head = malloc(sizeof(struct _list));
  if (head == NULL) {
    fprintf(stderr, "error malloc head\n");
    return 1;
  }

  list* tail = malloc(sizeof(struct _list));
  if (tail == NULL) {
    fprintf(stderrr, "error malloc tail\n");
    return 1;
  }
  
  head->next = tail;
  head->previous = NULL;
  tail->next = NULL;
  tail->previous = head;

  list->next = tail; // list points to one past the end of list
}

iterator begin(list* list)
{
  assert(list != NULL);

  iterator it;
  it = list->head->next;
  return it;
}

iterator end(list* list)
{
  assert(list != NULL);

  iterator it;
  it = list->tail;
  return it;
}

iterator next(iterator it)
{
  assert(list != NULL);
  //assert(it != NULL); // ?

  it = it->next;

  return it;
}

