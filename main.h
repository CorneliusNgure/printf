#ifndef _PRINTF_H
#define _PRINTF_H
#define output_buf_size 1024
#define buf_flush -1
#define NULL_STRING "(null)"
#define INITIALIZE_PARAMETERS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct parameters - parameters structures
 *
 * @unsign: flag if the value is unsigned.
 * @width: defines field width.
 * @precision: defines precision.
 * @flag_plus: if specified, on.
 * @h_modifier: if modified, on.
 * @space_flag: if specified, on.
 * @hashtag_flag: if specified, on.
 * @flag_zero: if specified, on.
 * @flag_minus: if specified, on
 * @l_modifier: on if specified.
 *
 */
typedef struct parameters
{
	unsigned int unsign		: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int flag_plus		: 1;
	unsigned int modifier_h		: 1;
	unsigned int flag_space		: 1;
	unsigned int flag_hashtag	: 1;
	unsigned int flag_zero		: 1;
	unsigned int flag_minus		: 1;
	unsigned int modifier_l		: 1;
} parameter_p;

/**
 * struct specifier - structure
 *
 * @specifier: format token
 * @f: function.
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, parameter_p *);
} specifier_t;

/* _put.c */
int _puts(char *str);
int _putchar(int c);

/* print_to_stdout.c */
int print_char(va_list ap, parameter_p *param);
int print_int(va_list ap, parameter_p *param);
int print_percent(va_list ap, parameter_p *param);
int print_S(va_list ap, parameter_p *param);
int print_string(va_list ap, parameter_p *param);

/* itoa_mimic.c */
char *converter(long int number, int base, int flags, parameter_p *param);
int print_unsigned(va_list ap, parameter_p *param);
int print_address(va_list ap, parameter_p *param);

/* specifier.c */
int (*get_specifier(char *s))(va_list ap, parameter_p *param);
int get_print_function(char *s, va_list ap, parameter_p *param);
int get_flag(char *s, parameter_p *param);
int get_modifier(char *s, parameter_p *param);
char *get_width(char *s, parameter_p *param, va_list ap);

/* number_converter.c */
int print_hex(va_list ap, parameter_p *param);
int print_HEX(va_list ap, parameter_p *param);
int print_binary(va_list ap, parameter_p *param);
int print_octal(va_list ap, parameter_p *param);

/* print_address.c */
int print_from_to(char *start, char *stop, char *except);
int print_in_reverse(va_list ap, parameter_p *param);
int print_rot13(va_list ap, parameter_p *param);

/* print_numerals.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, parameter_p *param);
int print_number_shift_right(char *str, parameter_p *param);
int print_number_shift_left(char *str, parameter_p *param);

/* parameter.c */
void init_params(parameter_p *param, va_list ap);

/* string_precision.c */
char *get_precision(char *p, parameter_p *param, va_list ap);

/* _prinf.c */
int _printf(const char *format, ...);

#endif

