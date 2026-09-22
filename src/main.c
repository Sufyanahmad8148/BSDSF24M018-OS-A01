#include <stdio.h>
#include <stdlib.h>

#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main(void)
{
    char text[100] = "Hello";
    char copy[100];

    int lines, words, chars;
    char** matches;
    int count;

    printf("--- Testing String Functions ---\n");

    printf("Length = %d\n", mystrlen(text));

    mystrcpy(copy, text);
    printf("Copy = %s\n", copy);

    mystrncpy(copy, "Operating Systems", 10);
    printf("N-Copy = %s\n", copy);

    mystrcat(text, " World");
    printf("Concatenation = %s\n", text);

    printf("\n--- Testing File Functions ---\n");

    FILE* file = fopen("sample.txt", "w");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    fprintf(file, "Operating Systems\n");
    fprintf(file, "Linux programming\n");
    fprintf(file, "Operating Systems Assignment\n");

    fclose(file);

    file = fopen("sample.txt", "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    if (wordCount(file, &lines, &words, &chars) == 0)
    {
        printf("Lines      = %d\n", lines);
        printf("Words      = %d\n", words);
        printf("Characters = %d\n", chars);
    }

    rewind(file);

    count = mygrep(file, "Operating", &matches);

    printf("Matches     = %d\n", count);

    for (int i = 0; i < count; i++)
    {
        printf("%s", matches[i]);
        free(matches[i]);
    }

    free(matches);
    fclose(file);

    return 0;
}
