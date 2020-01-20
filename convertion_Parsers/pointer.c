/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 04:20:12 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/20 08:46:22 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

void	parse_ptr(t_args *args)
{
	if (PRECISION < 0)
	{
		MINUS = 1;
		WIDTH = PRECISION * -1;
	}
	PRECISION -= LEN;
	WIDTH -= (PRECISION > 0) ? (PRECISION + LEN + 2) : (LEN + 2);
	ZERO = (IFPREC == 1) ? 0 : ZERO;
}

void	print_pointer(t_args *args, va_list pa)
{
	unsigned long long int	nb;
	char					*print;

	nb = va_arg(pa, unsigned long long int);
	print = convert(args, nb);
	LEN = ft_strlen(print);
	parse_ptr(args);
	if (MINUS <= 0 && WIDTH <= 0 && PRECISION <= 0 && IFPREC <= 0 && ZERO <= 0)
	{
		ft_putstrpr("0x", args);
		ft_putstrpr(print, args);
		return ;
	}
	if (ZERO)
		ft_putstrpr("0x", args);
	while (MINUS == 0 && WIDTH-- > 0)
		ZERO == 1 ? ft_putcharpr('0', args) : ft_putcharpr(' ', args);
	ft_putstrpr("0x", args);
	while (PRECISION-- > 0)
		ft_putcharpr('0', args);
	ft_putstrpr(print, args);
	while (WIDTH-- > 0)
		ft_putcharpr(' ', args);
	free(print);
}
