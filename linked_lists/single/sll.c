#include "sll.h"
#include <stdlib.h>
#include <stdio.h>


void print_list(node_t *head) 
{
	while (head) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}


void search(node_t *head, int key)
{
	while (head) 
	{
		if (head->data == key) {
			printf("%d found!\n", key);
			return;
		}
		head = head->next;
	}
	printf("%d not found!\n", key);
}

void delete_list(node_t **head) {
	node_t *temp;	// update head reference
	while (*head) {
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}


void delete_at(node_t **head, int idx) {
	// case 1: head is null
	if (*head == NULL)
	{
		printf("Head cannot be null...\n");
		return;
	}
	// case 2: delete head
	if (idx == 0) {
		node_t *temp = *head;
		*head = (*head)->next;
		free(temp);
		return;
	}
	node_t *temp;
	node_t *curr = *head;
	while (curr && idx) 
	{
		temp = curr;
		curr = curr->next;
		idx--;
	}
	// case 3: node is not in list
	if (curr == NULL)
	{
		printf("index exceeds list length...\n");
		return;
	}
	// case 4: node is in list
	temp->next = curr->next;
	free(curr);
}

void insert_at(node_t **head, int idx, int data)
{
	if (idx < 0) {
		printf("invalid index...\n");
		return;
	}
	// case 1: list is NUL
	if (*head == NULL)
	{
		if (idx > 0) {
			printf("invalid index...\n");
			return;
		}
		printf("list is null\n");
		node_t *newnode = malloc(sizeof(node_t));
		newnode->data = data;
		newnode->next = *head;
		*head = newnode;
		return;
	}
	// case 2: head exists but want to insert at head
	if (idx == 0)
	{
		//..de_t *temp = *head;
		node_t *newnode = malloc(sizeof(node_t));
		newnode->data = data;
		newnode->next = *head;
		*head = newnode;
		return;
	}
	node_t *prev;
	node_t *curr = *head;
	while (curr && idx) 
	{
		prev = curr;
		curr = curr->next;
		idx--;
	}
	if (idx) {
		printf("index is too large...\n");
		return;
	}
	if (curr == NULL) {
		printf("inserting at end of list\n");
		node_t *newnode = malloc(sizeof(node_t));
		newnode->data = data;
		newnode->next = NULL;
		prev->next = newnode;
	}
	else
	{
		printf("inserting in middle of list\n");
		node_t *newnode = malloc(sizeof(node_t));
		newnode->data = data;
		newnode->next = curr;
		prev->next = newnode;
	}
}


void push(node_t **head, int val) {
	node_t *newnode = malloc(sizeof(node_t));
	newnode->data = val;
	newnode->next = *head;
	*head = newnode;
}

void insert_sorted(node_t **head, int data) {
	// empty head
	if (*head == NULL) {
		node_t *newnode = malloc(sizeof(node_t));
		newnode->data = data;
		newnode->next = NULL;
		*head = newnode;
		return;
	}
	// insert at head
	if (data <= (*head)->data) {
		node_t *newnode = malloc(sizeof(node_t));
		newnode->data = data;
		newnode->next = *head;
		*head = newnode;
		return;		
	}
	node_t *prev;
	node_t *curr = *head;
//	printf("data is %d\n", data);
//	printf("curr data is %d\n", curr->data);	
//	printf("curr == NULL == %d\n", curr == NULL);
	while (curr && data > curr->data)
	{
//		printf("curr data is %d\n", curr->data);
		prev = curr;
		curr = curr->next;
	}
//	printf("outside\n");
	if (curr == NULL) 
	{
//		printf("hello\n");
		node_t *newnode = malloc(sizeof(node_t));
		newnode->data = data;
		newnode->next = NULL;
		prev->next = newnode;
		return;
	}
//	printf("%d %d\n", prev->data, curr->data);
	node_t *newnode = malloc(sizeof(node_t));
	newnode->data = data;
	newnode->next = curr;
	prev->next = newnode;
}


int has_cycle(node_t *head)
{
	if (head == NULL) { return 0; }
	node_t *slow = head;
	node_t *fast = head->next;
	while (slow != fast) 
	{
		if (fast == NULL || fast->next == NULL) { return 0; }
		slow = slow->next;
		fast = fast->next->next;
	}
	return 1;
}

void reverse(node_t **head)
{
	node_t *prev = NULL;  	// head of reverse list
	node_t *temp;		  	// hold head->next for forward list
	node_t *curr = *head; 	// hold head of forward list 
	while (curr) {
		temp = curr->next; 	// set to head->next  
		curr->next = prev; 	// set head->next = reverse head
		prev = curr;		// update reverse head to be forward head
		curr = temp;		// update forward head to be forward head->next
	}
	*head = prev;			// set head to reverse head
}