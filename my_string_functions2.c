#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination jfietjg
 * @src: the source hjfhg
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
int i;
if (dest == src || src == NULL)
return (dest);

i = 0;

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}

dest[i] = '\0';

return (dest);
}

/**
 * _strdup - duplicates a stringggg
 * @str: the string to duplicate jhj
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
if (str == NULL)
return (NULL);

char *ret = malloc(strlen(str) + 1);

if (ret != NULL)
strcpy(ret, str);

return (ret);
}

/**
 * _puts - prints an input string jij
 * @str: the string to be printed gjfkj
 *
 * Return: Nothing
 */
void _puts(char *str)
{
int i = 0;

if (!str)
return;

while (str[i] != '\0')
{
_putchar(str[i]);  /* Calls _putchar as in the original code */
i++;
}
}

/**
 * _putchar - writes the character c to stdout jjkj
 * @c: The character to printttt
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == -1 || i >= WRITE_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != -1)
buf[i++] = c;
return (1);
}
