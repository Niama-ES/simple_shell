#include "shell.h"
/**
 * get_environ - Returns a copy of the environment as a string array.
 * @info: Structure containing potential arguments.
 * Return: A copy of the environment as a string array, or NULL on failure.
 */
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}

return (info->environ);
}


/**
 * _unsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments.
 * @var: The name of the environment variable to remove.
 * Return: 1 on successful deletion, 0 otherwise.
 */
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
char *p;
size_t index = 0;
if (!node || !var)
return (0);

while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
info->env_changed = delete_node_at_index(&(info->env), index);
break;
}

node = node->next;
index++;
}

return (info->env_changed);
}

/**
 * set_env - Initialize a new environment variable or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 * Return: Always 0
 */
int set_env(info_t *info, char *var, char *value)
{
if (!var || !value)
return (0);

char *env_var = malloc(_strlen(var) + _strlen(value) + 2);
if (!env_var)
return (1);

snprintf(env_var, _strlen(var) + _strlen(value) + 2, "%s=%s", var, value);

list_t *node = info->env;
while (node)
{
char *p = starts_with(node->str, var);
if (p && *p == '=')
{
free(node->str);
node->str = env_var;
info->env_changed = 1;
return (0);
}
node = node->next;
}

add_node_end(&(info->env), env_var, 0);
info->env_changed = 1;
return (0);
}

