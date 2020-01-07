/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 04:16:23 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/04 05:27:20 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_int(t_args *args, long int nb)
{
	char	*len;

	len = ft_itoa(nb);
	LEN = (nb == 0 && IFPREC == 1 ? 0 : ft_strlen(len));
	nb < 0 ? LEN-- : LEN;
	MINUS = WIDTH < 0 || (PRECISION < 0 && STAR == 0) ? 1 : MINUS;
	WIDTH = WIDTH < 0 ? WIDTH * -1 : WIDTH;
	PRECISION = PRECISION < 0 && STAR == 0 ? PRECISION * -1 : PRECISION;
	PRECISION -= LEN;
	WIDTH -= PRECISION > 0 ? PRECISION + LEN : LEN;
	ZERO = (IFPREC == 1) && STAR == 0 ? 0 : ZERO;
}

void	print_int(t_args *args, va_list pa)
{
	long int nb;

	nb = assign_value(args, pa);
	parse_int(args, nb);
	while (MINUS == 0 && WIDTH-- > 0)
		ZERO == 1 ? ft_putcharpr('0', args) : ft_putcharpr(' ', args);
	while (PRECISION-- > 0)
		ft_putcharpr('0', args);
	if ((LEN > 0) || (nb == 0 && IFPREC == 0))
		ft_putnbrpr(nb, args);
	while (WIDTH-- > 0)
		ft_putcharpr(' ', args);
}
