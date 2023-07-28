#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: struct
 * @path: file path
 * Return: if successful 1 else 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - copies char
 * @pathstr: string path
 * @start: first index
 * @stop: last index
 * Return: points to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int m = 0, n = 0;

	for (n = 0, m = start; m < stop; m++)
		if (pathstr[m] != ':')
			buf[n++] = pathstr[m];
	buf[n] = 0;
	return (buf);
}

/**
 * find_path - finds the cmd path str
 * @info: struct
 * @pathstr:  file path
 * @cmd: the cmd to find
 * Return: Always 0
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int m = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[m] || pathstr[m] == ':')
		{
			path = dup_chars(pathstr, curr_pos, m);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[m])
				break;
			curr_pos = m;
		}
		m++;
	}
	return (NULL);
}
