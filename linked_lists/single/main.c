#include <stdlib.h>
#include <stdio.h>
#include "sll.h"


node_t *head = NULL;


int main()
{
  
  delete_list(&head);   

  printf("Testing push ...\n");
  push(&head, 33);
  push(&head, 22);
  push(&head, 11);
  print_list(head);
  delete_list(&head);

  printf("\n\n");
  printf("Testing insert_at ...\n");
  insert_at(&head, -1, 133); // invalid 
  insert_at(&head, 1, 133); // invalid 
  insert_at(&head, 0, 100); // insert at head of empty
  insert_at(&head, 0, 90); // insert at head of non-empty
  insert_at(&head, 2, 110); // insert at tail of non-empty
  insert_at(&head, 1, 105); // insert at mid of non-empty
  print_list(head);
  delete_list(&head);


  printf("\n\n");
  printf("Testing insert_sorted ...\n");
  insert_sorted(&head, 23); // insert empty
  insert_sorted(&head, 11); // insert front with non-empty
  insert_sorted(&head, 20); // insert mid with non-empty
  insert_sorted(&head, 30); // insert tail with non-empty
  print_list(head);
  delete_list(&head);


  printf("\n\n");
  printf("Testing search ...\n");
  search(head, 30);
  insert_sorted(&head, 23); // insert empty
  insert_sorted(&head, 11); // insert front with non-empty
  insert_sorted(&head, 20); // insert mid with non-empty
  insert_sorted(&head, 30); // insert tail with non-empty
  search(head, 30);
  search(head, 40);
  print_list(head);
  delete_list(&head);


  printf("\n\n");
  printf("Testing delete_at ...\n");
  insert_sorted(&head, 23); // insert empty
  insert_sorted(&head, 11); // insert front with non-empty
  insert_sorted(&head, 20); // insert mid with non-empty
  insert_sorted(&head, 30); // insert tail with non-empty
  print_list(head);
  delete_at(&head,0); // remove head non-empty
  print_list(head);
  delete_at(&head,1); // remove mid non-empty
  print_list(head);
  delete_at(&head,1); // remove tail non-empty
  print_list(head);
  delete_at(&head,0); // remove only non-empty
  print_list(head);
  delete_at(&head,0); // remove from null
  delete_list(&head);


  printf("\n\n");
  printf("Testing reverse ...\n");
  push(&head, 33);
  push(&head, 22);
  push(&head, 11);
  print_list(head);
  reverse(&head);
  print_list(head);
  reverse(&head);
  print_list(head);
  delete_list(&head);
  

  printf("\n\n");
  printf("Testing has cycle ...\n");
  push(&head, 33);
  push(&head, 22);
  push(&head, 11);
  // find tail node
  node_t *curr = head;
  while (curr->next) {
    curr = curr->next;
  }
  curr->next = head;  // create cycle
  printf("has_cycle = %d\n", has_cycle(head));
  curr->next = NULL;  // remove cycle
  delete_list(&head);
  return 0;
}
