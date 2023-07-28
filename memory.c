#include "shell.h"

/**
 * bfree - null the address and frees the pointer
 * @ptr: points to address
 * Return: if successful 1 else 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
