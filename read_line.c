#include "main.h"

/**
 * read_line - reads input string
 * @i_eof: return of getline func
 * Return: input string
 */

char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
