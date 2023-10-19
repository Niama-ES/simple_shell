#include "shell.h"
/**
 * clear_info - Initializes info_t struct
 * @info: Struct address
 */
void clear_info(info_t *info)
{
memset(info, 0, sizeof(info_t));
}

/**
 * set_info - Initializes info_t struct
 * @info: Struct address
 * @av: Argument vector
 */
void set_info(info_t *info, char **av)
{
if (info->arg)
{
info->argv = strtow(info->arg, " \t");
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}
info->argc = info->argv ? count_elements(info->argv) : 0;

replace_alias(info);
replace_vars(info);
}
info->fname = av[0];
}

/**
 * free_info - Frees info_t struct fields
 * @info: Struct address
 * @all: True if freeing all fields
 */
void free_info(info_t *info, int all)
{
if (all)
{
if (!info->cmd_buf)
free(info->arg);
if (info->env)
free_list(&(info->env));
if (info->history)
free_list(&(info->history));
if (info->alias)
free_list(&(info->alias));
ffree(info->environ);
bfree((void **)info->cmd_buf);
if (info->readfd > 2)
close(info->readfd);
_putchar(BUF_FLUSH);
}
ffree(info->argv);
info->argv = NULL;
info->path = NULL;
}

