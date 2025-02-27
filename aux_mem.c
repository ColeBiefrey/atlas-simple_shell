#include "main.h"

/**
 * _memcpy - copies info between void pointers
 * @newptr: destination pointer
 * @ptr: source pointer
 * @size: size of new pointer
 * Return: none
 */

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - reallocates memory block
 * @ptr: pointer to memory previously allocated
 * @old_size: size in bytes of the allocated space ptr
 * @new_size: new size in bytes of new memory block
 * Return: ptr
 * if new_size == old_size returns ptr without changes
 * if malloc fails return null
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - reallocates memory block of double pointer
 * @ptr: double pointer to memory previously allocated
 * @old_size: size in bytes of allocated space of ptr
 * @new_size: new size in bytes of new memory block
 * Return: ptr
 * if new_size == old_size returns ptr without changes
 * if malloc fails return null
 */

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
