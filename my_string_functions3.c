#include "shell.h"

/**
 * _strncpy - copies a string fgh
 * @dest: the destination string to be copied to fhtht
 * @src: the source stringfttjj
 * @n: the amount of characters to be copied hyt
 * Return: the concatenated string gyyh
 */
char *_strncpy(char *dest, const char *src, int n)
{
char *s = dest;
int i;

for (i = 0; i < n - 1 && src[i] != '\0'; i++)
{
dest[i] = src[i];
}

for (; i < n; i++)
{
dest[i] = '\0';
}

return (s);
}

/**
 * _strncat - concatenates two strings hjy
 * @dest: the first string gjy
 * @src: the second string vgh
 * @n: the maximum number of characterrrrs to append from src
 * Return: the concatenated stringggg
 */
char *_strncat(char *dest, const char *src, int n)
{
char *s = dest;
int i, j;

i = 0;
while (dest[i] != '\0')
{
i++;
}

j = 0;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}

if (j < n)
{
dest[i] = '\0';
}

return (s);
}

/**
 * _strchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look forrrr
 * Return: (s) a pointer to the memorrrry area s
 */
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
return (s);
s++;
}

return (NULL);
}
