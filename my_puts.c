#include "main.h"

/**
 * _puts - print string followed by a new line.
 * @str: string to be printed.
 *
 * Return: void
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes char to standard output
 * @c: char to be  printed
 *
 * Return: 1 when successful.
 * On error, -1 and errno is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[output_buf_size];

	if (c == buf_flush || i >= output_buf_size)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != buf_flush)
		buf[i++] = c;
	return (1);
}

