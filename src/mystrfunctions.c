#include "../include/mystrfunctions.h"

int mystrlen(const char* s)
{
    int i = 0;

    if (s == 0)
        return -1;

    while (s[i] != '\0')
        i++;

    return i;
}

int mystrcpy(char* dest, const char* src)
{
    int i = 0;

    if (dest == 0 || src == 0)
        return -1;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return i;
}

int mystrncpy(char* dest, const char* src, int n)
{
    int i = 0;

    if (dest == 0 || src == 0 || n <= 0)
        return -1;

    while (i < n - 1 && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return i;
}

int mystrcat(char* dest, const char* src)
{
    int i = 0;
    int j = 0;

    if (dest == 0 || src == 0)
        return -1;

    while (dest[i] != '\0')
        i++;

    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
    return i;
}
