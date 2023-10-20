#include "shell.h"


/**
 * is_cmd - determines if a file is an executable command dfjdkgj
 * @info: the info struct dfytg
 * @path: path to the file ftght
 *
 * Return: 1 if true, 0 otherwis e
 */
int is_cmd(info_t *info, char *path)
{
struct stat st;

if (path && !stat(path, &st) && S_ISREG(st.st_mode))
{
return (1);
}
return (0);
}

/**
 * dup_chars - duplicates characters ssdg
 * @pathstr: the PATH string gfghgf
 * @start: starting index fgyh
 * @stop: stopping index fht
 *
 * Return: pointer to new buffer 446
 */
char *dup_chars(char *pathstr, int start, int stop)
{
char *buf = malloc(stop - start + 1);
int i, k = 0;

if (buf == NULL)
return (NULL);

for (i = start; i < stop; i++)
{
if (pathstr[i] != ':')
{
buf[k++] = pathstr[i];
}
}

buf[k] = '\0';
return (buf);
}

/**
 * find_path - finds the cmd in the PATH string
 * @info: the info struct dfjrkt
 * @pathstr: the PATH string fdjgrk
 * @cmd: the cmd to find gfjkh
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
if (pathstr == NULL || cmd == NULL)
return (NULL);

if (strlen(cmd) > 2 && strncmp(cmd, "./", 2) == 0)
{
if (is_cmd(info, cmd))
return (cmd);
}

char *path;
char *token = strtok(pathstr, ":");

while (token != NULL)
{
path = malloc(strlen(token) + 1 + strlen(cmd) + 1);
/* +1 for '/', +1 for '\0' */
if (path == NULL)
return (NULL);

strcpy(path, token);
strcat(path, "/");
strcat(path, cmd);

if (is_cmd(info, path))
{
free(path);
return (path);
}

free(path);
token = strtok(NULL, ":");
}

return (NULL);
}
