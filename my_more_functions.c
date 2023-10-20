#include "shell.h"


/**
 * interactive - returns true if shell is in interactive modeeee
 * @info: pointer to a structttt
 *
 * Return: 1 if in interactive mode, 0 otherwise ou dkf
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if a character is a delimiterrrr
 * @c: the character to check kjfk
 * @delim: the delimiter string jsfdlk
 *
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
while (*delim != '\0')
{
if (*delim == c)
return (1);
delim++;
}
return (0);
}

/**
 * _isalpha - checks if a character issss an alphabetic character
 * @c: The character to check dkl
 *
 * Return: 1 if 'c' is alphabetic, 0 otherwise nkgf
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _atoi - converts a aaaa string to an integer
 * @s: the string to be converted jdfkke
 *
 * Return: 0 if no numbers in string, converted number otherwise jkfjgkrj
 */
int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result = result * 10 + (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}
