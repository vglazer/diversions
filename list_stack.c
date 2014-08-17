#include <stdlib.h>

/* singly-linked list node */
typedef struct node 
{
    double value;
    struct node * next;
} Node;

/* insert a new node at the front of the list */
Node *
insert_front(Node * head, double value)
{
    Node * new_head = malloc(sizeof(Node));
    
    new_head->value = value;
    new_head->next = head;

    return new_head;
}

/* driver */
int main(int argc, char const * argv[])
{
    return 0;
}
