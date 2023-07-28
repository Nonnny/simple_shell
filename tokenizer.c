#include "shell.h"

/**
 * **strtow - string into words.
 * @str: string to be input
 * @x: string delimiter
 * Return: Always 0
 */

char **strtow(char *str, char *x)
{
	int w, y, z, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!x)
		x = " ";
	for (w = 0; str[w] != '\0'; w++)
		if (!is_delim(str[w], x) && (is_delim(str[w + 1], x) || !str[w + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (w = 0, y = 0; y < numwords; y++)
	{
		while (is_delim(str[w], x))
			w++;
		z = 0;
		while (!is_delim(str[w + z], x) && str[w + z])
			z++;
		s[y] = malloc((z + 1) * sizeof(char));
		if (!s[y])
		{
			for (z = 0; z < y; z++)
				free(s[z]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < z; n++)
			s[y][n] = str[w++];
		s[w][z] = 0;
	}
	s[y] = NULL;
	return (s);
}

/**
 * **strtow2 - splits string
 * @str: the input string
 * @x: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char x)
{
	int w, y, z, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (w = 0; str[w] != '\0'; w++)
		if ((str[w] != x && str[w + 1] == x) ||
				    (str[w] != x && !str[w + 1]) || str[w + 1] == x)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (w = 0, y = 0; z < numwords; y++)
	{
		while (str[w] == x && str[w] != x)
			w++;
		z = 0;
		while (str[w + z] != x && str[w + z] && str[w + z] != x)
			z++;
		s[y] = malloc((z + 1) * sizeof(char));
		if (!s[y])
		{
			for (z = 0; z < y; z++)
				free(s[z]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < z; n++)
			s[y][z] = str[w++];
		s[y][n] = 0;
	}
	s[y] = NULL;
	return (s);
}
