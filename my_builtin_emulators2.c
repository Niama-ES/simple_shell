#include "shell.h"
/**
 * _myhistory - displays the command history with line numbers
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - removes an alias from the alias list
 * @info: Parameter struct
 * @str: The string representing the alias to unset
 *
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
char *equal_sign, saved_char;
int ret;

equal_sign = _strchr(str, '=');

if (!equal_sign)
return (1);

saved_char = *equal_sign;
*equal_sign = '\0';

ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));

*equal_sign = saved_char;

return (ret);
}

/**
 * set_alias - sets an alias to a string
 * @info: Parameter struct
 * @str: The string representing the alias
 *
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
char *equal_sign;

equal_sign = _strchr(str, '=');

if (!equal_sign)
return (1);

if (!*++equal_sign)
return (unset_alias(info, str));

unset_alias(info, str);

return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * _myalias - manage aliases, set or display them
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_list(node);
node = node->next;
}
return (0);
}

for (i = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], '=');

if (p)
set_alias(info, info->argv[i]);
else
{
node = node_starts_with(info->alias, info->argv[i], '=');

if (node)
print_list(node);
}
}

return (0);
}

