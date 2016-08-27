#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

int main(int argc, char * argv[]) 
{
    char buffer[BUFSIZE];
    int num, max_num, i, j;
    char * times_seen;

    /* validate arguments */
    if (argc != 2)
    {
        printf("usage: %s <max_num>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* times_seen[i] <- number of times we've seen i */
    max_num = atoi(argv[1]);
    if (max_num < 0)
    {
        puts("max_num cannot be negative!");
        return EXIT_FAILURE;
    }

    times_seen = calloc(max_num+1, 1);

    /* read in numbers one at a time */
    while (fgets(buffer, BUFSIZE, stdin) != NULL)
    {
        num = atoi(buffer);

        /* take care not to smash the stack */
        if (num < 0 || num > max_num)
        {
            printf("skipping %d\n", num);
            continue;
        }

        ++times_seen[num];
    }

    /* sorted output */
    for (i = 0; i <= max_num; ++i)
    {
        for (j = 0; j < times_seen[i]; ++j)
        {
            printf("%d\n", i);
        }
    }

    free(times_seen);

    return EXIT_SUCCESS;
}
