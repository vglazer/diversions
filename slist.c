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

/* remove and return the last element of the list */
Node *
pop_back(Node *head, 
         Node **back)
{
    Node *curr;

    /* empty list */
    if (head == NULL)
    {
        *back = NULL;
        return head;
    }
    /* singleton list */
    else if (head->next == NULL)
    {
        *back = head;
        return NULL;
    }
    /* at least two elements */
    else
    {
        /* need to find the element just before the last element */
        for (curr = head; curr->next->next != NULL; curr = curr->next);

        *back = curr->next;
        curr->next = NULL;

        return head;
    }
}

/* remove and return the first element of the list */
Node *
pop_front(Node *head, 
          Node **front)
{
    /* at least one element */
    if (head != NULL)
    {
        *front = head;
        head = head->next;
    }
    /* empty list */
    else
    {
        *front = NULL;
    }

    return head;
}

/* insert a new node at the front of the list */
Node *
push_front(Node *head, 
           double value)
{
    Node *new_head = malloc(sizeof(Node));
    
    new_head->value = value;
    new_head->next = head;

    return new_head;
}

/* insert a new node at the back of the list */
Node *
push_back(Node *head, 
          double value)
{
    Node *curr;

    /* handle empty lists separately, since head will change */
    if (head == NULL)
    {
        curr = malloc(sizeof(Node));
        
        curr->value = value;
        curr->next = NULL;

        return curr;
    }

    /* locate the end of the list */
    for (curr = head; curr->next != NULL; curr = curr->next);
    
    /* insert specified value */
    curr->next = malloc(sizeof(Node));

    curr->next->value = value;
    curr->next->next = NULL;

    return head;
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
    Node *node;
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
        if (!strcmp(line, "push_front"))
        {
            *head_ptr = push_front(*head_ptr, value);
            fprintf(log, "push_front -> %.2f\n", value);
        }
        else if (!strcmp(line, "push_back"))
        {
            *head_ptr = push_back(*head_ptr, value);
            fprintf(log, "push_back -> %.2f\n", value);
        }
        else if (!strcmp(line, "pop_front"))
        {
            *head_ptr = pop_front(*head_ptr, &node);
            if (node == NULL)
            {
                fprintf(log, "pop_front -> N/A\n");
            }
            else
            {
                fprintf(log, "pop_front -> %.2f\n", node->value);
            }

            /* reclaim memory */
            free(node);
        }
        else if (!strcmp(line, "pop_back"))
        {
            node = NULL;
            *head_ptr = pop_back(*head_ptr, &node);
            if (node == NULL)
            {
                fprintf(log, "pop_back -> N/A\n");
            }
            else
            {
                fprintf(log, "pop_back -> %.2f\n", node->value);
            }

            /* reclaim memory */
            free(node);
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
