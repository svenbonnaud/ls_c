# Mini LS Project

## What does the project do?

This project is a simple implementation of the `ls` command in C.  
It lists the contents of directories, with an option to show hidden files.

## Features

- Lists files and directories in a specified path.
- Supports the `-a` option to display hidden files.
- Handles errors when directories cannot be opened.

## Technologies Used

- C programming language
- System calls: `opendir()`, `readdir()`, `closedir()`
- Libraries: `<dirent.h>`, `<unistd.h>`, `<errno.h>`, `<string.h>`, `<stdlib.h>`

## How to Compile

Use the following command to compile the program:

```sh
gcc -Wall -Wextra -Werror -o mini_ls main.c ls.c

