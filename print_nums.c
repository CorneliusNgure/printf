#include "main.h"

/**
 * _isdigit - checks for digits
 * @c: char to be checked
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - string length.
 * @s: string to be checked.
 *
 * Return: string length.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number
 * @str: string's base #
 * @param: structure parameter.
 *
 * Return: chars to be printed.
 */
int print_number(char *str, parameter_p *param)
{
	unsigned int i = _strlen(str);
	int neg = (!param->unsign && *str == '-');

	if (!param->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (param->precision != UINT_MAX)
		while (i++ < param->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!param->flag_minus)
		return (print_number_shift_right(str, param));
	else
		return (print_number_shift_left(str, param));
}

/**
 * print_number_shift_right - prints a number
 * @str: string's base no.
 * @param: structure parameter.
 *
 * Return: characters to be printed.
 */
int print_number_shift_right(char *str, parameter_p *param)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (param->flag_zero && !param->flag_minus)
		pad_char = '0';
	neg = neg2 = (!param->unsign && *str == '-');
	if (neg && i < param->width && pad_char == '0' && !param->flag_minus)
		str++;
	else
		neg = 0;
	if ((param->flag_plus && !neg2) ||
		(!param->flag_plus && param->flag_space && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (param->flag_plus && !neg2 && pad_char == '0' && !param->unsign)
		n += _putchar('+');
	else if (!param->flag_plus && param->flag_space && !neg2 &&
		!param->unsign && param->flag_zero)
		n += _putchar(' ');
	while (i++ < param->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (param->flag_plus && !neg2 && pad_char == ' ' && !param->unsign)
		n += _putchar('+');
	else if (!param->flag_plus && param->flag_space && !neg2 &&
		!param->unsign && !param->flag_zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_shift_left - prints a number.
 * @str: string's base no.
 * @param: structure parameter.
 *
 * Return: characters to be printed.
 */
int print_number_shift_left(char *str, parameter_p *param)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (param->flag_zero && !param->flag_minus)
		pad_char = '0';
	neg = neg2 = (!param->unsign && *str == '-');
	if (neg && i < param->width && pad_char == '0' && !param->flag_minus)
		str++;
	else
		neg = 0;

	if (param->flag_plus && !neg2 && !param->unsign)
		n += _putchar('+'), i++;
	else if (param->flag_space && !neg2 && !param->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < param->width)
		n += _putchar(pad_char);
	return (n);
}
