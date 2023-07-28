#include "shell.h"

/**
 * _strlen - length of a string
 * @d: the string whose length to check
 * Return: Always 0
 */
int _strlen(char *d)
{
	int x = 0;

	if (!d)
		return (0);

	while (*d++)
		x++;
	return (x);
}

/**
 * _strcmp - compares two str
 * @d1: 1st string
 * @d2: 2nd string
 * Return: Always 0
 */
int _strcmp(char *d1, char *d2)
{
	while (*d1 && *d2)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		d1++;
		d2++;
	}
	if (*d1 == *d2)
		return (0);
	else
		return (*d1 < *d2 ? -1 : 1);
}

/**
 * starts_with - checks for needle in a pile
 * @haystack: search string
 * @needle: search sub-string
 * Return: Always 0
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - puts two strings
 * @dest: destination buf
 * @src: buf
 * Return: Always 0
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
