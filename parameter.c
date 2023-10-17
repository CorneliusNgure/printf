#include "main.h"

/**
 * init_params - clears structure fields and reset the buffer.
 * @param: structure parameter.
 * @ap: argument (pointer).
 *
 * Return: void
 */
void init_params(parameter_p *param, va_list ap)
{
	param->unsign = 0;

	param->width = 0;
	param->precision = UINT_MAX;
	param->flag_plus = 0;
	param->modifier_h = 0;
	param->flag_space = 0;
	param->flag_hashtag = 0;
	param->flag_zero = 0;
	param->flag_minus = 0;
	param->modifier_l = 0;
	(void)ap;
}
