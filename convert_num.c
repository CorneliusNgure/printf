#include "main.h"

/**
 * print_hex - prints unsigned #hex in lowercase
 * @ap: pointer argument.
 * @param: structure parameter.
 *
 * Return: printed bytes.
 */
int print_hex(va_list ap, parameter_p *param)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (param->modifier_l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->modifier_h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = converter(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, param);
	if (param->flag_hashtag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	param->unsign = 1;
	return (c += print_number(str, param));
}

/**
 * print_HEX - prints unsigned #hex in uppercase.
 * @ap: pointer argument.
 * @param: structure parameter.
 *
 * Return: printed bytes.
 */
int print_HEX(va_list ap, parameter_p *param)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (param->modifier_l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->modifier_h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = converter(l, 16, CONVERT_UNSIGNED, param);
	if (param->flag_hashtag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	param->unsign = 1;
	return (c += print_number(str, param));
}
/**
 * print_binary - prints binary numbers.
 * @ap: pointer argument.
 * @param: structure parameter.
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, parameter_p *param)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = converter(n, 2, CONVERT_UNSIGNED, param);
	int c = 0;

	if (param->flag_hashtag && n)
		*--str = '0';
	param->unsign = 1;
	return (c += print_number(str, param));
}

/**
 * print_octal - prints octal #s.
 * @ap: argument pointer.
 * @param: strutcture parameter.
 *
 * Return: printed bytes.
 */
int print_octal(va_list ap, parameter_p *param)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (param->modifier_l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->modifier_h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = converter(l, 8, CONVERT_UNSIGNED, param);

	if (param->flag_hashtag && l)
		*--str = '0';
	param->unsign = 1;
	return (c += print_number(str, param));
}

