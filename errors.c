#include "shell.h"

/**
 * _eputs - prints a string
 * @str: is the string printed
 * Return: Always 0
 */
void _eputs(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_eputchar(str[y]);
		y++;
	}
}

/**
 * _eputchar - writes character c to stderr
 * @c: prints character
 * Return: if successful 1 else -1
 */
int _eputchar(char c)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(2, buf, y);
		y = 0;
	}
	if (c != BUF_FLUSH)
		buf[y++] = c;
	return (1);
}

/**
 * _putfd - writes character c to fd
 * @c: prints character
 * @fd: filedescriptor to write
 * Return:  if successful 1 else -1
 */
int _putfd(char c, int fd)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(fd, buf, y);
		y = 0;
	}
	if (c != BUF_FLUSH)
		buf[y++] = c;
	return (1);
}

/**
 * _putsfd - print input string
 * @str: prints string
 * @fd: filedescriptor to write
 * Return: Always 0
 */
int _putsfd(char *str, int fd)
{
	int y = 0;

	if (!str)
		return (0);
	while (*str)
	{
		y += _putfd(*str++, fd);
	}
	return (y);
}
