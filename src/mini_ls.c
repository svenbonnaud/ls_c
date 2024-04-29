#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include "ls.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void write_open_dir(DIR *dir, int hidden_show)
{
    struct dirent *c_e;
    char **file_names;
    int i;
    int j;

    file_names = malloc(256 * sizeof(char *));
    i = 0;
    j = 0;
    while ((c_e = readdir(dir)) != NULL) {
        if (hidden_show || c_e->d_name[0] != '.') {
            file_names[i] = c_e->d_name;
            i += 1;
        }
    }
    strtab_sort(file_names);
    while (j < i) {
        write(1, file_names[j], stu_strlen(file_names[j]));
        write(1, " ", 1);
        j += 1;
    }
    free(file_names);
}


void error_message(int i, char **av)
{
    char *str;

    if (errno != 0 && av[i][0] != '-') {
        str = strerror(errno);
        write(1, av[0], stu_strlen(av[0]));
        write(1, ": ", 2);
        write(1, av[i], stu_strlen(av[i]));
        write(1, ": ", 2);
        write(1, str, stu_strlen(str));
        write(1, "\n", 1);
    } else {
        return;
    }
}

void stu_mini_ls(int ac, char **av)
{
    int i;
    DIR *dir;
    int show_hidden;

    i = 1;
    show_hidden = 0;
    while (i < ac) {
        dir = opendir(av[i]);
        if (stu_strcmp(av[i], "-a") == 0)
            show_hidden = 1;

        if (dir != NULL) {
            write(1, av[i], stu_strlen(av[i]));
            write(1, ":\n", 2);
            write_open_dir(dir, show_hidden);
            closedir(dir);
        } else {
            error_message(i, av);
        }
        i += 1;
        write(1, "\n", 1);
    }
}
