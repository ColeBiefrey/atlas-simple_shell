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
