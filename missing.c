#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SENLEN 51
#define RESLEN 27

/* Remove trailing newline, if any */
void chomp(char *string)
{
    size_t len = strlen(string);

    if (string[len - 1] == '\n')
        string[len - 1] = '\0';
}

/* Store the characters missing from sentence in result,
 * ignoring case */
void getMissingLetters(char *result, char *sentence)
{
    int charvec[26], i, j;
    char *pos;

    /* Scan sentence to build up characteristic vector charvec */
    memset(charvec, 0, sizeof(charvec));
    for (pos = sentence; *pos != '\0'; ++pos)
    {
        /* Ignore case and throw away non-letters; shift
         * letters down to conserve space */
        i = toupper(*pos) - 'A';
        if (0 <= i && i <= 25)
            charvec[i] = 1;
    }

    /* Scan charvec, adding missing characters to result */
    for (i = 0, j = 0; i <= 25; ++i)
        if (charvec[i] == 0)
            result[j++] = 'A' + i;

    /* Terminate result string */
    result[j] = '\0';
}

/* Test harness for getMissingLetters() */
int main(void)
{
    char sentence[SENLEN], result[RESLEN];

    printf("Input sentence: "); 
    fgets(sentence, SENLEN, stdin);
    chomp(sentence);

    getMissingLetters(result, sentence);

    printf("The missing letters are: %s\n", result);

    return 0;
}

