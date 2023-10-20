#include "shell.h"

/**
 * _strlen - returns the length of a string dfjektg
 * @s: the string whose length to check dgjrky
 *
 * Return: integer length of the string fgfg
 */
int _strlen(char *s)
{
int length = 0;

if (s == NULL)
return (0);

while (s[length] != '\0')
length++;

return (length);
}

/**
 * _strcmp - performs lexicographic comparison of two strings vckgj
 * @s1: the first string hgf
 * @s2: the second string gfjh
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
return (*s1 - *s2);
}

/**
 * starts_with - checks if haystack starts with needle dfrjg
 * @haystack: string to search hgjf
 * @needle: the substring to find hjgh
 *
 * Return: address of the next character in haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
{
if (*needle != *haystack)
return (NULL);
needle++;
haystack++;
}
return (*haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination bufferrr
 * @src: the source bufferrrr hgh
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;

while (*src)
*dest++ = *src++;

*dest = '\0';

return (ret);
}
