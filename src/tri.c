#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "ls.h"

int try_ascii(char *str1, char *str2)
{
    int i;

    i = 0;
    if (str1 == NULL || str2 == NULL)
        return 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 1;
        }
        else if (str1[i] < str2[i]) {
            return -1;
        }
        i += 1;
    }
    if (str1[i] == '\0' && str2[i] != '\0')
        return -1;
    else if (str1[i] != '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;
}

void strtab_sort(char **strtab)
{
    int s;
    int length;
    int j;
    char *tmp;

    if (strtab == NULL || strtab[0] == NULL)
        return;
    length = 0;
    s = 0;
    while (strtab[length] != NULL) {
        length += 1;
    }
    while (!s) {
        j = 0;
        s = 1;
        while (j < (length - 1)) {
            if (try_ascii(strtab[j], strtab[j + 1]) > 0) {
                tmp = strtab[j];
                strtab[j] = strtab[j + 1];
                strtab[j + 1] = tmp;
                s = 0;
            }
            j += 1;
        }
    }
}
