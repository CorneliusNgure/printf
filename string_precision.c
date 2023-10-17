#include "main.h"

/**
 * get_precision - gets precision from the input string.
 * @p: format string
 * @param: param structure.
 * @ap: arg pointer.
 *
 * Return: pointer
 */
char *get_precision(char *p, parameter_p *param, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	param->precision = d;
	return (p);
}

