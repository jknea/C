typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node_t;



void push(node_t **head, node_t **tail, int data);

void insert_at(node_t **head, node_t **tail, int idx, int data);



void delete_node(node_t **head, node_t **tail, int data);

void delete_at(node_t **head, node_t **tail, int idx);




void delete_list_from_head(node_t **head, node_t **tail);

void delete_list_from_tail(node_t **head, node_t **tail);



void head_traverse(node_t *head);

void tail_traverse(node_t *tail);