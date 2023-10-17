#include "main.h"

/**
 * print_from_to - prints a range of character addresses.
 * @start: first address
 * @stop: last  address
 * @except: except address
 *
 * Return: bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_in_reverse - prints string in reverse
 * @ap: string
 * @param: struct parameter.
 *
 * Return: # of bytes printed
 */
int print_in_reverse(va_list ap, parameter_p *param)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)param;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @ap: string
 * @param: structure parameter.
 *
 * Return: no. of bytes printed.
 */
int print_rot13(va_list ap, parameter_p *param)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)param;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}

