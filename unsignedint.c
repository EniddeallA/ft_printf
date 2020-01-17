/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignedint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 04:14:47 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/17 11:36:35 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_unsigned_int(t_args *args)
{
	MINUS = PRECISION < 0 ? 1 : MINUS;
	WIDTH = (PRECISION < 0) ? PRECISION * -1 : WIDTH;
	PRECISION -= LEN;
	WIDTH -= PRECISION > 0 ? PRECISION + LEN : LEN;
	ZERO = IFPREC == 1 ? 0 : ZERO;
}

void	print_unsigned_int(t_args *args, va_list pa)
{
	unsigned long long int	nb;
	char					*print;

	nb = assign_value(args, pa);
	print = convert(args, nb);
	LEN = ft_strlen(print);
	parse_unsigned_int(args);
	if (MINUS == 0)
		while (WIDTH-- > 0)
			ZERO == 1 ? ft_putcharpr('0', args) : ft_putcharpr(' ', args);
	while (PRECISION-- > 0)
		ft_putcharpr('0', args);
	ft_putstrpr(print, args);
	WIDTH = WIDTH < 0 ? WIDTH * -1 - (2 * LEN + 1) : WIDTH * 1;
	while (WIDTH-- > 0)
		ft_putcharpr(' ', args);
	free(print);
}