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

/* print node values to stddout */
void
print_list(FILE * output_stream, Node * head)
{
    Node * curr;

    for (curr = head; curr != NULL; curr = curr->next)
    {
        fprintf(output_stream, "%.2f\n", curr->value);
    }
}

/* driver */
int main(int argc, char const * argv[])
{
    Node * head;
    FILE * output_stream;

    /* output goes to stdout by default, but user can specify file */
    if (argc > 2)
    {
        printf("usage: %s <input file> [output file]\n", argv[0]);
        return EXIT_FAILURE;
    }
    else if (argc == 2)
    {
        output_stream = fopen(argv[1], "w");
    }
    else
    {
        output_stream = stdout;
    }

    head = insert_front(NULL, 5.0);
    head = insert_front(head, 7.2);

    print_list(output_stream, head);

    fclose(output_stream);

    return EXIT_SUCCESS;
}
