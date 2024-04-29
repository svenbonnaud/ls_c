#ifndef MINI_LS_H_
#define MINI_LS_H_
unsigned int stu_strlen(const char *str);
char *stu_strcpy(char *dest, const char *src);
char *stu_strdup(char *str);
int stu_strcmp(const char *s1, const char *s2);
void stu_mini_ls(int ac, char **av);
int try_ascii(char *str1, char *str2);
void strtab_sort(char **strtab);
#endif
