#include "shell.h"
/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _getenv - Get the value of an environment variable.
 * @info: Pointer to the structure containing environment variables.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: The value of the environment variable if found; otherwise, NULL.
 */
char *_getenv(info_t *info, const char *name)
{
for (list_t *node = info->env; node; node = node->next)
{
char *p = starts_with(node->str, name);
if (p && *p)
return (p);
}
return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments.
 * Return: 0 if successful, 1 on failure.
 */
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguments\n");
return (1);
}
return (_setenv(info, info->argv[1], info->argv[2]) ? 0 : 1);
}

/**
 * _myunsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments.
 * Return: 0 if successful, 1 on failure.
 */
int _myunsetenv(info_t *info)
{
if (info->argc == 1)
{
_eputs("Too few arguments.\n");
return (1);
}

for (int i = 1; i < info->argc; i++)
{
if (!_unsetenv(info, info->argv[i]))
return (0);
}

return (0);
}

/**
 * populate_env_list - Populates the environment linked list.
 * @info: Structure containing potential arguments.
 * Return: 0 if successful, 1 on failure.
 */
int populate_env_list(info_t *info)
{
list_t *node = NULL;

for (size_t i = 0; environ[i]; i++)
{
add_node_end(&node, environ[i], 0);
}

info->env = node;
return (0);
}

