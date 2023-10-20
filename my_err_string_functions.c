#include "shell.h"
/**
 * eputs - Print an input string
 * @str: The string to be printed
 *
 * Return: Nothing
 */
void eputs(char *str)
{
int i;
if (!str)
return;

for (i = 0; str[i] != '\0'; i++)
{
_eputchar(str[i]);
}
}

/**
 * eputchar - Write the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
if (write(2, buf, i) == -1)
{
return (-1);
}
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putfd - Writes the character 'c' to the given file descriptor 'fd'.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Return: On success, it returns 1.
 * On error, it returns -1, and sets 'errno' appropriately.
 */
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
ssize_t written = write(fd, buf, i);
if (written == -1)
{
perror("write");
return (-1);
}
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;

return (1);
}

/**
 * _putsfd - prints an input string to a file descriptor
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters written
 */
int _putsfd(char *str, int fd)
{
int i = 0;
if (str == NULL)
return (0);
while (str[i] != '\0')
{
if (_putfd(str[i], fd) == -1)
return (-1);
i++;
}

return (i);
}

