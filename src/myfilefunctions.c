#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/myfilefunctions.h"

int wordCount(FILE* file, int* lines, int* words, int* chars)
{
    int ch;
    int in_word = 0;

    if (file == 0 || lines == 0 || words == 0 || chars == 0)
        return -1;

    *lines = 0;
    *words = 0;
    *chars = 0;

    while ((ch = fgetc(file)) != EOF)
    {
        (*chars)++;

        if (ch == '\n')
            (*lines)++;

        if (isspace((unsigned char)ch))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            (*words)++;
            in_word = 1;
        }
    }

    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches)
{
    char buffer[1024];
    int count = 0;
    char** temp;

    if (fp == 0 || search_str == 0 || matches == 0)
        return -1;

    *matches = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        if (strstr(buffer, search_str) != NULL)
        {
            temp = realloc(*matches, (count + 1) * sizeof(char*));

            if (temp == NULL)
                return -1;

            *matches = temp;

            (*matches)[count] = malloc(strlen(buffer) + 1);

            if ((*matches)[count] == NULL)
                return -1;

            strcpy((*matches)[count], buffer);
            count++;
        }
    }

    return count;
}
