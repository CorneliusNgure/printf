#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list ap, parameter_p * param)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_in_reverse},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_function - finds the function
 * @s: format string
 * @ap: ptr arg.
 * @param: structure parameter.
 *
 * Return: # of bytes printed
 */
int get_print_function(char *s, va_list ap, parameter_p *param)
{
	int (*f)(va_list, parameter_p *) = get_specifier(s);

	if (f)
		return (f(ap, param));
	return (0);
}

/**
 * get_flag - gets flag function.
 * @s: format string.
 * @param: parameter structure.
 *
 * Return: flag.
 */
int get_flag(char *s, parameter_p *param)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = param->flag_plus = 1;
			break;
		case ' ':
			i = param->flag_space = 1;
			break;
		case '#':
			i = param->flag_hashtag = 1;
			break;
		case '-':
			i = param->flag_minus = 1;
			break;
		case '0':
			i = param->flag_zero = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - gets the modifier.
 * @s: format string.
 * @param: parameter structure.
 *
 * Return: return modifier if valid.
 */
int get_modifier(char *s, parameter_p *param)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = param->modifier_h = 1;
		break;
	case 'l':
		i = param->modifier_l = 1;
		break;
	}
	return (i);
}

/**
 * get_width - width of the string.
 * @s: string.
 * @param: parameter strucutre.
 * @ap: arg ptr.
 *
 * Return: new ptr.
 */
char *get_width(char *s, parameter_p *param, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	param->width = d;
	return (s);
}
