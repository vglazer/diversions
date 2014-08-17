#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024

/* singly-linked list node */
typedef struct node 
{
    double value;
    struct node *next;
} Node;

/* insert a new node at the front of the list */
Node *insert_front(Node *head, double value)
{
    Node *new_head = malloc(sizeof(Node));
    
    new_head->value = value;
    new_head->next = head;

    return new_head;
}

/*  node values to log */
void print_list(Node *head, FILE *log)
{
    Node *curr;

    fprintf(log, "list contents\n");
    for (curr = head; curr != NULL; curr = curr->next)
    {
        fprintf(log, "%.2f\n", curr->value);
    }
}

/* parse commands file and invoke appropriate function, logging the results */
Node *dispatch(Node **head_ptr, FILE *commands, char delim, FILE *log)
{
    char buffer[BUFSIZE], *temp;
    double value;

    while (fgets(buffer, BUFSIZE, commands) != NULL)
    {
        for (temp = buffer; *temp != '\0' && *temp != delim; ++temp);
        if (*temp == '\0')
        {
            fprintf(stderr, "no delimeter found; skipping %s", buffer);
            continue;
        }

        *temp = '\0';
        ++temp;

        value = atof(temp);
        if (!strcmp(buffer, "insert_front"))
        {
            *head_ptr = insert_front(*head_ptr, value);
            fprintf(log, "insert_front -> %f\n", value);
        }
        else
        {
            fprintf(stderr, "unknown command; skipping %s\n", buffer);
            continue;
        }
    }

    return *head_ptr;
}

/* 
    reads commands from stdin; writes results to stdout and errors to stderr.
    sample usage: cat commands.txt  | ./slist > log.txt
*/
int main(int argc, char const *argv[])
{
    Node *head;

    head = NULL;
    head = dispatch(&head, stdin, ',', stdout);

    print_list(head, stdout);

    return EXIT_SUCCESS;
}
