#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @x: points to memory
 * @y: to fill @x with
 * @z: bytes to fill
 * Return: Always 0
 */
char *_memset(char *x, char y, unsigned int z)
{
	unsigned int a;

	for (a = 0; a < z; a++)
		x[a] = y;
	return (x);
}

/**
 * ffree - free strings
 * @pp: strings
 */
void ffree(char **pp)
{
	char **n = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(n);
}

/**
 * _realloc - allots memory block
 * @ptr: pointers to previous block
 * @old_size: byte size of block
 * @new_size: size of new block
 * Return: Always 0
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *i;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	i = malloc(new_size);
	if (!i)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		i[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (i);
}
