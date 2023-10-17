#include "main.h"

/**
 * print_char - prints character
 * @ap: argument(pointer)
 * @param: structure.
 *
 * Return: chars printed
 */
int print_char(va_list ap, parameter_p *param)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (param->flag_minus)
		sum += _putchar(ch);
	while (pad++ < param->width)
		sum += _putchar(pad_char);
	if (!param->flag_minus)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @ap: pointer argument
 * @param: structure parameter
 *
 * Return: characters  printed.
 */
int print_int(va_list ap, parameter_p *param)
{
	long l;

	if (param->modifier_l)
		l = va_arg(ap, long);
	else if (param->modifier_h)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(converter(l, 10, 0, param), param));
}

/**
 * print_string - prints string
 * @ap: argument
 * @param: struct param.
 *
 * Return: # of chars printed
 */
int print_string(va_list ap, parameter_p *param)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)param;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (param->precision < pad)
		j = pad = param->precision;

	if (param->flag_minus)
	{
		if (param->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < param->width)
		sum += _putchar(pad_char);
	if (!param->flag_minus)
	{
		if (param->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - prints string
 * @ap: argument
 * @param: parameters structure
 *
 * Return: # of  characters printed.
 */
int print_percent(va_list ap, parameter_p *param)
{
	(void)ap;
	(void)param;
	return (_putchar('%'));
}

/**
 * print_S - customized format specifier
 * @ap: argument
 * @param: structure
 *
 * Return: # of characters printed
 */
int print_S(va_list ap, parameter_p *param)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = converter(*str, 16, 0, param);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
