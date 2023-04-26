#ifndef MAIN_H
#define MAIN_H

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

char cwd[MAX_COMMAND_LENGTH];
extern char **environ;

void loop(void);
char *kpsh_get_input();
char **kpsh_split_strings(char *str);
int execute_command(char **args);
void kpsh_exit(char **args, int num_args);
int get_num_args(char **args);
void change_directory(char **args);
void set_env(char** args);
void unset_env(char** args);
char *handle_path(char **args);

/* custom functions */
char *my_strchr(const char *str, int ch);
char *my_strtok(char *str, const char *delim);
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);
int my_putchar(int c);
void my_printf(char *format, ...);
int my_snprintf(char *str, size_t size, const char *format, ...);

#endif

