#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>


#define DELIMITER " \t\r\n"
#define BUFF_SIZE 1024
#define MAX_INPUT_LENGTH 1024
#define MAX_COMMAND_LENGTH 100



extern char **environ;

void loop(void);
char *kpsh_get_input();
char **kpsh_split_strings(char *str);
int execute_command(char **args, char *input);
void kpsh_exit(char **args);
int get_num_args(char **args);
void change_directory(char **args);
void set_env(char **args);
void unset_env(char **args);
char *handle_path(char **args);

/* custom functions */
char *my_strchr(const char *str, int ch);
char *my_strtok(char *str, const char *delim);
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);
int my_putchar(int c);
void my_printf(char *format, ...);

/*more function prototypes */
char *my_getenv(const char *name);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_memcpy(char *dest, char *src, unsigned int n);
void *my_realloc(void *ptr, unsigned int new_size);
char *my_strcat(char *dest, const char *src);
int my_strcmp(char *fs1, char *ss2);
char *my_strncpy(char *desti, const char *src, int b);
int my_strileng(const char *s);
char *my_strcpy(char *dest, const char *src);
int my_atoi(char *s);

int check_args(char **args, char *input);

#endif
