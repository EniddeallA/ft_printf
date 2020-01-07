/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:21:24 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/06 06:52:32 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_args(t_args *args)
{
	args->minus = 0;
	args->zero = 0;
	args->ptr = 1;
	args->ifprec = 0;
	args->star = 0;
	args->conv = 0;
	args->width = 0;
	args->precision = 0;
	args->res = 0;
	args->len = 0;
}

int		printf_(char *format, va_list pa)
{
	t_args	args;
	int		i;
	int		res;
	int		start;

	i = 0;
	start = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			print(start, i, format);
			res += i - start;
			zero_args(&args);
			format_handler(format, &i, &args, pa);
			args.conv != 0 && args.conv != -1 ? i++ : i;
			print_format(&args, pa);
			res += args.res;
			start = i;
		}
		format[i] != '\0' && format[i] != '%' ? i++ : i;
	}
	print(start, i, format);
	return (res + i - start);
}

int		ft_printf(const char *format, ...)
{
	va_list	pa;
	int		res;

	va_start(pa, format);
	res = printf_((char *)format, pa);
	va_end(pa);
	return (res);
}
