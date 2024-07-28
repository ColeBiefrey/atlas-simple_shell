#include "main.h"

/**
 * get_sigint - Handle crtl+c call
 * @sig: signal handler
 */

void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
