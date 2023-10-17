#include "main.h"

/**
 * _printf - prints characters, strings and numerals.
 * @format: the format string
 *
 * Return: bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	parameter_p param = INITIALIZE_PARAMETERS;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&param, ap);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &param))
		{
			p++;
		}
		p = get_width(p, &param, ap);
		p = get_precision(p, &param, ap);
		if (get_modifier(p, &param))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
				param.modifier_l || param.modifier_h ? p - 1 : 0);
		else
			sum += get_print_function(p, ap, &param);
	}
	_putchar(buf_flush);
	va_end(ap);
	return (sum);
}
