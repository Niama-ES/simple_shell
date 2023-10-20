#include "shell.h"
#include <math.h>
/**
 * _erratoi - converts a string to an integerrrr
 * @s: the string to be converted fdjgk
 *
 * Return: 0 if no numbers in string, converted 55dkdf  number otherwise
 *         -1 on error
 */
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;

if (*s == '+')
s++;  /* Skips the optional plus sign */

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');

if (result > INT_MAX)
return (-1);
}
else
{
return (-1);  /* Invalid character encountered*/
}
}

return (result);
}

/**
 * print_error - prints an error message ker
 * @info: pointer to the parameter and return infoooo struct
 * @estr: string containing the specified error typeeeee
 */
void print_error(info_t *info, char *estr)
{
fprintf(stderr, "%s: %d: %s: %s\n", info->fname
, info->line_count, info->argv[0], estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10) 100
 * @input: the input tt
 * @fd: the file descriptor toooo write toooo
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa hhh
 * @num: number hhhh
 * @base: base
 * @flags: argument flagsssss
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
static char buffer[50];
char *ptr = buffer;
char sign = 0;
char *start;
char *end;
unsigned long n = num;
const char *array = (flags & CONVERT_LOWERCASE
) ? "0123456789abcdef" : "0123456789ABCDEF";

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}

do {
*ptr++ = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*ptr++ = sign;

*ptr = '\0';

/* Reverse the string */
start = buffer;
end = ptr - 1;
while (start < end)
{
char temp = *start;
*start = *end;
*end = temp;
start++;
end--;
}

return (buffer);
}

/**
 * remove_comments - function replaces the first instance o
 * f '#' with '\0' nnggg
 * @buf: address of the string to modify  9999
 *
 * Return: Always 0
 */
void remove_comments(char *buf)
{
int i;

for (i = 0; buf[i] != '\0'; i++)
{
if (buf[i] == '#' && (i == 0 || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}
}
