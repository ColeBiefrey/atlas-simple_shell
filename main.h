#ifndef _MAIN_
#define _MAIN_

/* Headers, including UNIX based, that will be used throughout the program */
/* Will add a file explaining the specifics and how I intend to use them later */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Sets default buffer and token to be processed */
#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/**
 * struct data - this struct contains all relevant data for runtime
 * @av: argument vector
 * @input: command line written by user
 * @args: tokens of command line
 * @status: last status of shell
 * @counter: line counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */

typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - SLL
 * @separator: ; | &
 * @next: next node
 * Description: single linked list that stores separators
 */

typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - SLL
 * @line: command line
 * @next: next node
 * Description: single linked list that stores command lines
 */

typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - SLL
 * @len_var: length of variable
 * @val: value of variable
 * @len_val: length of value
 * @next: next node
 * Description: single linked list for vars
 */

typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - builtin struct for put args
 * @name: name of command builtin i.e env, cd, ect
 * @f: data type pointer function
 */

typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* cmd_exe.c proxys */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

/* cd.c proxys */
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

/* cd_shell.c proxys */
int cd_shell(data_shell *datash);

/* exit_shell.c proxys */
int exit_shell(data_shell *datash);

#endif