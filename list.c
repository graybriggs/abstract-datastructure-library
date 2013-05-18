

#include "list.h"


// I'm debating whether to change this init function to:
// int init_list_s(list_s*);

list_s* init_list_s()
{
	list_s* head = (list_s*)malloc(sizeof(list));
	head->next = NULL;
	head->data = NULL;
	head->size = 0;

	return head;
}

/* since a singly linked list, must iterate over the entire list to rear
   O(n) */
void insert_rear_s(list_s* head, void* data)
{
  assert(head != NULL);
  assert(data != NULL);

  list_s* new_node;

  if (head->next == NULL) {
    new_node = (list_s*)malloc(sizeof(list));
    new_node->next = NULL;
    new_node->data = data;
    head->next = new_node;
    ++head->size;
  }
  else {
    list_s* temp = head->next;

    while (temp->next != NULL) {
      temp = temp->next;
    }

    new_node = (list_s*)malloc(sizeof(list));
    new_node->next = NULL;
    new_node->data = data;
    temp->next = new_node;
    ++head->size;
  }
}


void insert_front_s(list* head, void* data)
{
  assert(head != NULL);
  assert(data != NULL);

  if (head->next == NULL) {
    list* new_node = (list*)malloc(sizeof(list));
    new_node->next = NULL;
    new_node->data = data;
    head->next = new_node;
    ++head->size;
  }
  else {
    list* temp = head->next;
    list* new_node = (list*)malloc(sizeof(list));
    new_node->next = temp;
    new_node->data = data;
    head->next = new_node;
    ++head->size;
  }
}


void insert_at_s(list_s* head, void* data, int pos)
{
  assert(head != NULL);
  assert(data != NULL);

  list_s* temp = head->next;
  list_s* save;
  list_s* new_node;

  if (pos == 0) {
    new_node = (list_s*)malloc(sizeof(list_s*));
    new_node->next = head->next;
    new_node->data = data;
    head->next = new_node;
    ++head->size;
  }
  else {
    int counter = 1;

    while (counter < pos) {
      temp = temp->next;
      ++counter;
    }
    save = temp->next;
    new_node = (list_s*)malloc(sizeof(list));
    new_node->data = data;
    new_node->next = save;
    temp->next = new_node;
    ++head->size;
  }
}


void* get_at_s(list_s* head, int pos)
{
  assert(head != NULL);

  list_s* temp;
  int counter;
  
  if (head == NULL) {
    return NULL;
  }
  temp = head->next;
  counter = 0;
  if (pos >= size(head)) { // position is outside list boundary
    printf("outside boundary\n");
    return NULL;
  }
  else if (!is_empty(head)) {  // empty list
    printf("empty\n");
    return NULL;
  }
  else {
    while (counter < pos) {
      temp = temp->next;
      ++counter;
    }
    return temp->data;
  }
}


int delete_at_s(list* head, int pos)
{
  assert(head != NULL);

  list* temp = head->next;
  list* save;
  int counter = 1;

  // out of list range
  if (pos > size(head) - 1) {
    return -1;
  }
  else if (pos == 0) {
    head->next = temp->next;
    printf("Deleting position 0: %f\n", (*(float*)temp->data));
    free(temp->data);
    free(temp);
    --head->size;
    return 0;
  }
  else {
    while (counter < pos) {
      temp = temp->next;
      counter++;
    }
		
    save = temp->next->next;
    printf("Deleting %f\n", (*(float*)temp->next->data));
    free(temp->next->data);
    free(temp->next);
    temp->next = save;
    --head->size;
    return 0;
  }
}

int is_empty_s(list_s* head)
{
  assert (head != NULL);

  (head->next == NULL) ? 1 : 0;
}

size_t size_s(list_s* head)
{
  assert(head != NULL);

  return head->size;
}

void delete_list_s(list_s* head)
{
  assert(head != NULL);
  
  int s = size(head);

  while (s >= 0) {
    delete_at(head, s);
    s--;
  }

  free(head);
}


/////////////////////////////////////////////////////////
/////////* Doubly linked list implementation *///////////
/////////////////////////////////////////////////////////


int init_list_d(list_d* list)
{
  assert(list == NULL);

  list->head = malloc(sizeof(list_d));
  list->tail = malloc(sizeof(list_d));

  if (list->head == NULL || list->tail == NULL) {
    return -1;
  }

  list->head->next = tail;
  list->head->previous = NULL;
  list->head->data = NULL;  // this value should not be modified again
  list->head.size = 0;  // this value should not be modified again
  list->data = NULL;
  list->size = 0;

  list->tail->next = NULL;
  list->tail->previous = head;
  list->tail->data = NULL; // this value should not be modified again
  list->tail.size = 0;  // this value should not be modified again
  list->data = NULL;
  list->size = 0;

  return 1;
}

int insert_front_d(list_d* list, void* data)
{
  assert (list != NULL);

  list_d* new_node = malloc(sizeof(list_d*));
  if (new_node == NULL) {
    return -1;
  }

  if (list->head->next == list->tail) {
    new_node->next = list->tail;
    new_node->previous = list->head;
    new_node->data = data;

    list->head->next = new_node;
    list->head->previous = NULL; // remains same
    ++list->head.size;

    list->tail->next = NULL; // remains same
    list->tail->previous = new_node;
    ++list->tail.size;
  }
  else {
    new_node->next = head->next;
    new_node->previous = list->head;
    new_node->data = data;
    ++new_node.size;

    list->head->next = new_node;
    list->tail->previous = new_node;
    ++list->head.size;
    ++list->tail.size;
  }
  return 1;
}

int is_empty_d(list_d* list)
{
  assert(list != NULL);

  if (list->head->size == 0) {
    return 1;
  }
  else {
    return 0;
  }
}
