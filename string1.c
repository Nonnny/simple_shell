#include "shell.h"

/**
 * _strcpy - string to be copied
 * @dest: the destination
 * @src: the source
 * Return: Always 0
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

/**
 * _strdup - copies a str
 * @str: string to be copied
 * Return: Always 0
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - inputs a string
 * @str: printed string
 * Return: Always 0
 */
void _puts(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
}

/**
 * _putchar - writes the character d
 * @d: print char
 * Return: if successful 1 else -1
 */
int _putchar(char d)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (d BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (d != BUF_FLUSH)
		buf[x++] = d;
	return (1);
}
