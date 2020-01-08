/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 05:05:35 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/07 22:26:24 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_parse(t_args *args)
{
	ZERO = PRECISION < 0 ? 0 : ZERO;
	LEN = (PRECISION < LEN && IFPREC == 1) ? PRECISION : LEN;
	WIDTH = WIDTH < 0 && CONV == 'c' ? WIDTH * -1 : WIDTH;
	WIDTH = (PRECISION < 0) ? PRECISION * -1 : WIDTH - LEN;
	WIDTH = (CONV == 'c' && PRECISION < 0) ? (PRECISION * -1) - 1 : WIDTH;
	MINUS = (CONV == 'c' && PRECISION < 0) ? 1 : MINUS;
	if (IFPREC == 1 && PRECISION == 0 && CONV == 'c')
		WIDTH--;
}

void	print_string(t_args *args, va_list pa)
{
	char	*str;

	str = va_arg(pa, char *);
	str = (str == NULL ? "(null)" : str);
	LEN = ft_strlen(str);
	printf_parse(args);
	while (MINUS == 0 && WIDTH-- > 0)
		ZERO == 1 ? ft_putcharpr('0', args) : ft_putcharpr(' ', args);
	while (LEN-- > 0 && *str != '\0')
		ft_putcharpr(*str++, args);
	while (WIDTH-- > 0)
		ft_putcharpr(' ', args);
}

void	print_char(t_args *args, va_list pa)
{
	unsigned char x;

	x = (unsigned char)va_arg(pa, int);
	LEN = 1;
	printf_parse(args);
	while (MINUS == 0 && WIDTH-- > 0)
		ZERO == 1 ? ft_putcharpr('0', args) : ft_putcharpr(' ', args);
	ft_putcharpr(x, args);
	while (WIDTH-- > 0)
		ft_putcharpr(' ', args);
}
