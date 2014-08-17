#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1024

/* singly-linked list node */
typedef struct node 
{
    double value;
    struct node *next;
} Node;

/* insert a new node at the front of the list */
Node *
insert_front(Node *head, 
                   double value)
{
    Node *new_head = malloc(sizeof(Node));
    
    new_head->value = value;
    new_head->next = head;

    return new_head;
}

/*  node values to log */
void 
print_list(Node *head, 
           FILE *log)
{
    Node *curr;

    fprintf(log, "list contents:\n");
    for (curr = head; curr != NULL; curr = curr->next)
    {
        fprintf(log, "%.2f\n", curr->value);
    }
}

/* parse commands file and invoke appropriate function, logging the results */
Node *
dispatch(Node **head_ptr, 
               char delim, 
               FILE *commands, 
               FILE *log,
               FILE *errors)
{
    char line[MAX_LENGTH], *cursor;
    double value;

    while (fgets(line, MAX_LENGTH, commands) != NULL)
    {
        /* look for the delimeter. if it's not there, the line is malformed */
        for (cursor = line; *cursor != '\0' && *cursor != delim; ++cursor);
        if (*cursor == '\0')
        {
            fprintf(errors, "no delimeter found; skipping %s", line);
            continue;
        }

        /* break up the line into command followed by value */
        *cursor = '\0';
        ++cursor;

        /* extract value */
        value = atof(cursor);

        /* process command if we know how */
        if (!strcmp(line, "insert_front"))
        {
            *head_ptr = insert_front(*head_ptr, value);
            fprintf(log, "insert_front -> %f\n", value);
        }
        else
        {
            fprintf(errors, "unknown command; skipping %s\n", line);
            continue;
        }
    }

    return *head_ptr;
}

/* 
    read commands from stdin; log results to stdout and errors to stderr.
    sample usage: cat commands.txt  | ./slist > log.txt
*/
int 
main(int argc, 
     char const *argv[])
{
    Node *head = NULL;
    FILE *commands = stdin, *log = stdout, *errors = stderr;

    head = dispatch(&head, ',', commands, log, errors);
    print_list(head, log);

    return EXIT_SUCCESS;
}
