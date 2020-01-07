/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 04:19:46 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/04 07:29:07 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print(int start, int i, char *format)
{
	while (start < i && format[start] != '\0')
		write(1, &format[start++], 1);
}

void				print_format(t_args *args, va_list pa)
{
	if (CONV == '%' || CONV == -1)
		print_perc(args);
	else if (CONV == 's')
		print_string(args, pa);
	else if (CONV == 'c')
		print_char(args, pa);
	else if (CONV == 'd' || CONV == 'i')
		print_int(args, pa);
	else if (CONV == 'p')
		print_pointer(args, pa);
	else if (CONV == 'u' || CONV == 'x' || CONV == 'X')
		print_unsigned_int(args, pa);
}

void				print_perc(t_args *args)
{
	int	width;

	width = 0;
	while (MINUS == 0 && width++ < WIDTH - 1)
		ZERO == 1 ? ft_putcharpr('0', args) : ft_putcharpr(' ', args);
	if (CONV != -1)
		ft_putcharpr('%', args);
	while (width++ < WIDTH - 1)
		ZERO == 1 ? ft_putcharpr('0', args) : ft_putcharpr(' ', args);
}

long	long	int	assign_value(t_args *args, va_list pa)
{
	if (CONV == 'd' || CONV == 'i')
		return ((int)va_arg(pa, void*));
	if (CONV == 'u' || CONV == 'X' || CONV == 'x')
		return ((unsigned int)va_arg(pa, void*));
	return ((long long int)NULL);
}

char				*convert(t_args *args, long long int nb)
{
	if (CONV == 'x' || CONV == 'X' || CONV == 'p')
		return (CONV == 'X' ? ft_convert_hex(nb, 1) : ft_convert_hex(nb, 0));
	if (CONV == 'u')
		return (ft_itoa(nb));
	return (NULL);
}
