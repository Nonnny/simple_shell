#include "shell.h"

/**
 **_strncpy - the string to be copied
 *@dest: where the string is copied to
 *@src: source string
 *@b: char to be copied
 *Return: string
 */
char *_strncpy(char *dest, char *src, int b)
{
	int g, h;
	char *s = dest;

	g = 0;
	while (src[g] != '\0' && g < b - 1)
	{
		dest[g] = src[g];
		g++;
	}
	if (g < b)
	{
		h = g;
		while (g < b)
		{
			dest[h] = '\0';
			h++;
		}
	}
	return (s);
}

/**
 **_strncat - adds two strings
 *@dest: 1st string
 *@src: 2nd string
 *@b: no of bytes used
 *Return: the added string
 */
char *_strncat(char *dest, char *src, int b)
{
	int g, h;
	char *s = dest;

	g = 0;
	h = 0;
	while (dest[g] != '\0')
		g++;
	while (src[h] != '\0' && h < b)
	{
		dest[g] = src[h];
		g++;
		h++;
	}
	if (h < b)
		dest[g] = '\0';
	return (s);
}

/**
 **_strchr - find char in str
 *@x: str to be parsed
 *@y: char to find
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *x, char y)
{
	do {
		if (*x == y)
			return (x);
	}
	while (*x++ != '\0');

	return (NULL);
}
