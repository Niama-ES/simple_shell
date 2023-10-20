#include "shell.h"
/**
 * bfree - frees a pointer and NULLs the address AAAA
 * @ptr: address of the pointer to free eeeee
 *
 * Return: 1 if freed, otherwise 0 or 555
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
