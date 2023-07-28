#include "shell.h"

/**
 * _erratoi - convert a string to  int
 * @s: string to be converted
 * Return: if successful 0 else -1
 */
int _erratoi(char *s)
{
	int x = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (x = 0;  s[x] != '\0'; x++)
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			result *= 10;
			result += (s[x] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints a message error
 * @info: info struct
 * @estr: contains specified error type of string
 * Return: if successful 0 else -1
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: is the input
 * @fd: filedescriptor to write
 * Return: Always 0
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int x, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (_abs_ / x)
		{
			__putchar('0' + current / x);
			count++;
		}
		current %= x;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - convers function of a no
 * @num: is the no
 * @base: base
 * @flags: args of flags
 * Return: Always 0
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long y = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		y = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[y % base];
		y /= base;
	} while (y != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - replaces function
 * @buf: string to modify
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
		if (buf[x] == '#' && (!x || buf[x - 1] == ' '))
		{
			buf[x] = '\0';
			break;
		}
}
