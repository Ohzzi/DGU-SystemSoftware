typedef struct _node {
    int ADR;
    int len;
    struct _node* next;
} node;

void add(node* cursor, int ADR, int len);