

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


void insert_at(list* head, void* data, int pos)
{
	list* temp = head->next;
	list* save;
	list* new_node;

	if (pos == 0) {
		new_node = (list*)malloc(sizeof(list*));
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
		new_node = (list*)malloc(sizeof(list));
		new_node->data = data;
		new_node->next = save;
		temp->next = new_node;
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
	int s = size(head);

	while (s >= 0) {
		delete_at(head, s);
		s--;
	}

	//free(head);
}
