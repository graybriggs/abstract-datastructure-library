

#include "list.h"

list* init_list()
{
	list* head = (list*)malloc(sizeof(list));
	head->next = NULL;
	head->data = NULL;
	head->size = 0;

	return head;
}

/* since a singly linked list, must iterate over the entire list to rear
   O(n) */
void insert_rear(list* head, void* data)
{
	list* new_node;
	float* f;

	if (head->next == NULL) {
		new_node = (list*)malloc(sizeof(list));
		new_node->next = NULL;
		new_node->data = data;
		head->next = new_node;
		++head->size;
	}
	else {
		list* temp = head->next;

		while (temp->next != NULL) {
			temp = temp->next;
		}

		new_node = (list*)malloc(sizeof(list));
		new_node->next = NULL;
		new_node->data = data;
		temp->next = new_node;
		++head->size;
	}
	f = (float*)new_node->data;
}


void insert_front(list* head, void* data)
{
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


void* get_at(list* head, int pos)
{
	list* temp;
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


int delete_at(list* head, int pos)
{
	list* temp = head->next;
	list* cur;
	list* save_node;
	int counter = 0;
	while (counter != pos - 1) {
		temp = temp->next;
		++counter;
	}
	cur = temp;
	save_node = temp->next->next;
	temp = temp->next;
	free(temp->data);
	free(temp);
	cur->next = save_node;
}

int is_empty(list* head)
{
	(head->next == NULL) ? 1 : 0;
}

size_t size(list* head)
{
	return head->size;
}

void delete_list(list* head)
{
	list* cur;
	if (head->next != NULL) {
		cur = head->next;
		while (cur->next != NULL) {
			list* temp = cur->next;
			free(cur->data);
			free(cur);
			cur = temp;
		}
		free(cur->data);
		free(cur);
	}
	free(head);
}

/**********/

void print_list(list* in_list)
{
	list* temp = in_list;
	while (temp->next != NULL) {
		printf("%d\n", temp->data);
	}
}