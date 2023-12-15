#ifndef MAIN_H
#define MAIN_H

/* Standard I/O functions */
#include <stdio.h>
/*  Standard library for memory allocation, process control, etc. */
#include <stdlib.h>
/* Provides access to the POSIX operating system API */
#include <unistd.h>
/* String handling functions */
#include <string.h>
/* Definitions of a number of data types used in system calls */
#include <sys/types.h>
/*  Defines the structure of the data returned */
/* by the functions fstat(), lstat(), and stat() */
#include <sys/stat.h>
#include <sys/wait.h>
/*  Declarations for waiting for process termination */
#include <stdbool.h>
/* Boolean data type */
#include <ctype.h>
/*  Character type functions */

/* Function prototypes for shell operations */
char *read_user_input(void);
void free2DArray(char **arr);
int runCommand(char **command, char **argv, int idx);
char **splitStringIntoTokens(char *line);
char *matchedEnv(char *variable);
char *path(char *command);
void displayError(char *name, char *cmd, int idx);
char *integer_to_string(int number);
void reverseStr(char *str, int length);
int CheckTheGivenCommandIsBuiltIn(char *command);
void executeBuiltinCommand(char **command, char **argv, int *status, int idx);
void terminateShell(char **command, char **argv, int *status, int idx);
void displayEnvironmentVariables(char **command, int *status);
int st_to_int(char *str);
int is_numeric_string(char *str);

/* Macro for token delimiters in command parsing */
#define DELIM " \t\n"

/* Additional utility function prototypes */
char *duplicateString(char *str);
int compareStrings(char *str1, char *str2);
int stringLength(char *str);
char *concatenateStrings(char *dest, char *src);
char *copyString(char *dest, char *src);

/* External environment variable from the OS */
extern char **environ;

/* Function prototypes for token counting and allocation in command parsing */
int count_tokens(char *line);
char **allocate_tokens_array(int count);
void populate_tokens_array(char **command, char *line);

#endif /* MAIN_H */
