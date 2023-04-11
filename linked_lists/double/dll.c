#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void push(node_t **head, node_t **tail, int data) {
    // if empty list
    if (*head == NULL) {
        node_t *newnode = malloc(sizeof(node_t));
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        *head = newnode;
        *tail = newnode;
        return;
    }
    node_t *newnode = malloc(sizeof(node_t));
    newnode->data = data;
    newnode->next = *head;
    newnode->prev = NULL;
    (*head)->prev = newnode;
    *head = newnode;
}


void insert_at(node_t **head, node_t **tail, int idx, int data)
{
    if (idx < 0) {
        return;
    }
    if (*head == NULL) 
    {
        // insert node at head
        if (idx > 0) {
            return;
        }
        node_t *newnode = malloc(sizeof(node_t));
        newnode->next = NULL;
        newnode->prev = NULL;
        newnode->data = data;
        *head = newnode;
        *tail = newnode;
        return;
    }
    if ((*head)->next == NULL)
    {
        if (idx > 1) 
        {
            return;
        }
        if (idx == 0)
        {
            printf("case 5\n");
            // update head
            node_t *newnode = malloc(sizeof(node_t));
            newnode->next = *head;
            (*head)->prev = newnode;
            newnode->prev = NULL;
            newnode->data = data;
            *head = newnode;
            return;
        }
        // idx == 1, update tail
        node_t *newnode = malloc(sizeof(node_t));
        newnode->next = NULL;
        newnode->prev = *head;
        (*head)->next = newnode;
        newnode->data = data;
        *tail = newnode;
        return;
    }
    node_t *curr = *head;
    node_t *prev;
    while (curr && idx)
    {
        prev = curr;
        curr = curr->next;
        idx--;
    }

    if (idx > 0) {
        // insert past tail node
        return;
    }
 
    if (curr == NULL)
    {
        node_t *newnode = malloc(sizeof(node_t));
        newnode->next = NULL;
        newnode->prev = prev;
        prev->next = newnode;
        newnode->data = data;
        *tail = newnode;
        return;
    }
    // insert somewhere in the middle
    node_t *newnode = malloc(sizeof(node_t));
    newnode->next = curr;
    curr->prev = newnode;
    newnode->prev = prev;
    prev->next = newnode;
    newnode->data = data;
}


void delete_node(node_t **head, node_t **tail, int data) {
    node_t *curr = *head;
    while (curr != NULL && curr->data != data) {
        curr = curr->next;
    }
    if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }
    if (curr == NULL) return;    // not found;
    if (curr->next == NULL) {
        // delete tail
        curr->prev->next = NULL;
        *tail = curr->prev;
        free(curr);
        return;
    }
    else if (curr->prev == NULL) {
        // delete head node
        curr->next->prev = NULL;
        *head = curr->next;
        free(curr);
        return;
    }
    else {
        // delete somewhere between head and tail
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
        return;
    }
}




void delete_at(node_t **head, node_t **tail, int idx)
{
    if (idx < 0) {
//        printf("invalid idx...\n");    
 //       printf("case 1\n");
        return;
    }
    if (*head == NULL)
    {
  //      printf("case 2\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        if (idx > 0) 
        {
  //          printf("case 3\n");
            return;
        }
        // only one node
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }
    // more than two nodes
    node_t *curr = *head;
    node_t *prev;
    idx++;      // adjust for base zero indexing
    while (curr && idx)
    {
        prev = curr;
        curr = curr->next;
        idx--;
    }
    if (curr == NULL)
    {
        if (idx > 0)
        {
            // try to delete past end of list
//            printf("case 4\n");
            return;
        }
//        printf("case 5\n");
        // delete tail
        prev->prev->next = NULL;
        *tail = prev->prev;
        free(prev);
        return;
    }
    // delete prev node, somewhere in the middle
//    printf("case 6\n");
    prev->prev->next = curr;
    curr->prev = prev->prev;
    free(prev);
}


void delete_list_from_head(node_t **head, node_t **tail)
{
    node_t *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *tail = NULL;
}


void delete_list_from_tail(node_t **head, node_t **tail)
{
    node_t *temp;
    while (*tail)
    {
        temp = *tail;
        *tail = (*tail)->prev;
        free(temp);
    }
    *head = NULL;
}




void head_traverse(node_t *head) {
    node_t *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void tail_traverse(node_t *tail) {
    node_t *curr = tail;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}