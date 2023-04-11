#include <stdio.h>
#include "dll.h"

node_t *head = NULL;
node_t *tail = NULL;

void test_insert_at();
void test_push();
void test_delete_node();
void test_delete_at();

int main() {



    test_push();
    test_insert_at();
    test_delete_node();
    test_delete_at();

    return 0;
}

void test_push()
{
    printf("\n\n");
    printf("Testing push()\n");
    push(&head, &tail, 22);     // push to empty
    push(&head, &tail, 33);     // push to non-empty
    head_traverse(head);        // forward traverse
    tail_traverse(tail);        // reverse traverse
    delete_list_from_head(&head, &tail);    // delete from head
    // test again with delete from tail
    push(&head, &tail, 22);
    push(&head, &tail, 33);
    delete_list_from_tail(&head, &tail);
    head_traverse(head);
    tail_traverse(tail);
}

void test_insert_at()
{
    printf("\n\n");
    printf("Testing insert_at()\n");
    insert_at(&head, &tail, 2, 100);    // invalid
    insert_at(&head, &tail, -1, 100);    // invalid
    insert_at(&head, &tail, 0, 100);    // insert head empty
    insert_at(&head, &tail, 2, 500);    
    insert_at(&head, &tail, 0, 50);    // insert head two nodes
    insert_at(&head, &tail, 1, 150);    // insert middle 
    insert_at(&head, &tail, 3, 300);    // insert tail non-empty
    head_traverse(head);        // forward traverse
    delete_list_from_head(&head, &tail);    // delete from head
    insert_at(&head, &tail, 0, 100);    // insert head empty
    insert_at(&head, &tail, 1, 200);    // insert head empty
    insert_at(&head, &tail, 3, 200);    // insert head empty
    delete_list_from_tail(&head, &tail);    // delete from head
}

void test_delete_node()
{
    printf("\n\n");
    printf("testing delete_node\n");
    delete_node(&head, &tail, 44); // delete from empty
    push(&head, &tail, 22);     // push to empty
    delete_node(&head, &tail, 44); // delete non-existant, non-empty
    delete_node(&head, &tail, 22); // delete only node
    push(&head, &tail, 22);     // push to empty
    push(&head, &tail, 33);     
    push(&head, &tail, 44);     
    push(&head, &tail, 55);     
    push(&head, &tail, 66);     
    delete_node(&head, &tail, 66); // delete head
    delete_node(&head, &tail, 22); // delete tail
    delete_node(&head, &tail, 44); // delete middle
    delete_node(&head, &tail, 33); // delete head, two only
    push(&head, &tail, 33);
    delete_node(&head, &tail, 55); // delete tail, two only
    head_traverse(head);
    tail_traverse(tail);
    delete_list_from_head(&head, &tail);
}



void test_delete_at()
{
    printf("\n\n");
    printf("testing delete_at\n");
    delete_at(&head, &tail, -1);
    delete_at(&head, &tail, 0);
    push(&head, &tail, 11);
    delete_at(&head, &tail, 1);
    delete_at(&head, &tail, 0);
    push(&head, &tail, 11);
    push(&head, &tail, 21);
    push(&head, &tail, 31);
    delete_at(&head, &tail, 3);
    delete_at(&head, &tail, 2);
    push(&head, &tail, 31);
    delete_at(&head, &tail, 1);
    delete_list_from_head(&head, &tail);
}