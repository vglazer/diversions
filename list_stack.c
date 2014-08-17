#include <stdlib.h>
#include <stdio.h>

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

void
print_list(Node * head)
{
    Node * curr;

    for (curr = head; curr != NULL; curr = curr->next)
    {
        printf("%.2f\n", curr->value);
    }
}

/* driver */
int main(int argc, char const * argv[])
{
    Node * head; 

    head = insert_front(0, 5.0);
    head = insert_front(head, 7.2);

    print_list(head);

    return 0;
}
