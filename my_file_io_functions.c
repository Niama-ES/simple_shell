#include "shell.h"
/**
 * get_history_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containing the history file
 */
char *get_history_file(info_t *info)
{
size_t dir_len = _strlen(dir);
char *dir = _getenv(info, "HOME=");
if (!dir)
return (NULL);
size_t hist_file_len = _strlen(HIST_FILE);
char *buf = malloc(dir_len + hist_file_len + 2);
if (!buf)
{
free(dir);
return (NULL);
}
buf[0] = '\0';
_strcpy(buf, dir);
_strcat(buf, "/");
_strcat(buf, HIST_FILE);
free(dir);
return (buf);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
{
int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
char *filename = get_history_file(info);
list_t *node = info->history;
if (!filename)
return (-1);
free(filename);
if (fd == -1)
return (-1);
while (node)
{
if (_putsfd(node->str, fd) == -1 || _putfd('\n', fd) == -1)
{
close(fd);
return (-1);
}
node = node->next;
}
if (_putfd(BUF_FLUSH, fd) == -1)
{
close(fd);
return (-1);
}
if (close(fd) == -1)
return (-1);
return (1);
}

/**
 * read_history - reads history from a file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
int i, last = 0, linecount = 0;
ssize_t rdlen, fsize = 0;
struct stat st;
char *buf = NULL, *filename = get_history_file(info);
int fd;
if (!filename)
return (0);
fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);
if (fstat(fd, &st) == 0)
fsize = st.st_size;
if (fsize < 2)
{
close(fd);
return (0); }
buf = malloc(fsize + 1);
if (!buf)
{
close(fd);
return (0); }
rdlen = read(fd, buf, fsize);
buf[fsize] = '\0';
if (rdlen <= 0)
{
close(fd);
free(buf);
return (0);
}
close(fd);
for (i = 0; i < fsize; i++)
{
if (buf[i] == '\n')
{
buf[i] = '\0';
build_history_list(info, buf + last, linecount++);
last = i + 1;
}}
if (last != i)
build_history_list(info, buf + last, linecount++);
free(buf);
info->histcount = linecount;
while (info->histcount >= HIST_MAX)
{
delete_node_at_index(&(info->history), 0);
info->histcount--; }
renumber_history(info);
return (info->histcount);
}
/**
 * build_history_list - Add an entry to a history linked list.
 * @info: Structure containing potential arguments. Used to maintain.
 * @buf: Buffer containing the entry to be added.
 * @linecount: The history line count (histcount).
 *
 * Return: Always 0.
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *new_entry = NULL;
if (!info->history)
info->history = new_entry;
else
new_entry = info->history;
add_node_end(&new_entry, buf, linecount);
return (0);
}
/**
 * renumber_history - Renumber the history linked list after changes.
 * @info: Structure containing potential arguments. Used to maintain.
 *
 * Return: The new histcount.
 */
int renumber_history(info_t *info)
{
list_t *current_entry = info->history;
int new_histcount = 0;
while (current_entry)
{
current_entry->num = new_histcount++;
current_entry = current_entry->next;
}
info->histcount = new_histcount;
return (new_histcount);
}
