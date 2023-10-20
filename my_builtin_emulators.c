#include "shell.h"
/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 *         (0) if info->argv[0] != "exit"
 *         (1) if an illegal number is provided as an argument
 */
int _myexit(info_t *info)
{
int exit_status = 0;
if (info->argv[1])  /* If there is an exit argument */
{
int exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
exit_status = 1;
}
else
{
info->err_num = exitcheck;
}
}
else
{
info->err_num = -1;
}
return (exit_status);
}
/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_ret;
s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: Handle getcwd failure error message here\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
{
_puts("TODO: Handle directory not found error message here\n");
chdir_ret = /* TODO: Set appropriate return value */;
}
else
chdir_ret = chdir(dir); }
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1); }
_puts(_getenv(info, "OLDPWD="));
_putchar('\n');
chdir_ret = /* TODO: Set appropriate return value */; }
else
{
chdir_ret = chdir(info->argv[1]); }
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]);
_eputchar('\n'); }
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024)); }
return (0);
}
/**
 * _myhelp - displays help information for the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
char **arg_array;
arg_array = info->argv;
_puts("Add your help information here.\n");
if (0)
_puts(*arg_array); /* Temporarily unused workaround */
return (0);
}
