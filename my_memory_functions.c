#include "shell.h"
/**
 * _memset - fills memory with a constant byteeee
 * @s: the pointer to the memoryyyy area
 * @b: the byte to fill *s with 333
 * @n: the amount of bytes to be filled
 * Return: a pointer to the memory areaaa s
 */
char *_memset(char *s, char b, unsigned int n)
{
char *start = s;

while (n > 0)
{
*s = b;
s++;
n--;
}

return (start);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
char **ptr = pp;

if (!pp)
return;

while (*ptr)
{
free(*ptr);
ptr++;
}

free(pp);
}

/**
 * _realloc - reallocates a block of memoryyyy
 * @ptr: pointer to previous malloc'ated blockkkk
 * @old_size: byte size oooof the previous block
 * @new_size: byte size of the new block dk
 * Return: pointer to the reallocated block jrg
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr;

if (!ptr)
return (malloc(new_size));

if (!new_size)
{
free(ptr);
return (NULL);
}

if (new_size == old_size)
return (ptr);

new_ptr = malloc(new_size);
if (!new_ptr)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
new_ptr[old_size] = ((char *)ptr)[old_size];

free(ptr);
return (new_ptr);
}
