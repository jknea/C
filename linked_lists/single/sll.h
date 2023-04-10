// Compilers can "align" members internally to match the underlying instruction architecture, which generally will increase the structs size. The tradeoff is that they can access data more quickly.
typedef struct node
{
  struct node *next;
  int data;
} node_t;



void print_list(node_t *head);

void search(node_t *head, int key);



void delete_at(node_t **head, int idx);

void delete_list(node_t **head);



void push(node_t **head, int val);

void insert_sorted(node_t **head, int data);

void insert_at(node_t **head, int idx, int data);



void reverse(node_t **head);

int has_cycle(node_t *head);