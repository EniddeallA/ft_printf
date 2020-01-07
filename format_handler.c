/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 05:26:19 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/04 07:18:10 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_handler(char *f, int *i, t_args *args, va_list pa)
{
	*i += 1;
	while (f[*i] && (f[*i] == '.' || f[*i] == '-' || f[*i] == '0' ||
				f[*i] == '*' || (f[*i] >= '0' && f[*i] <= '9')))
	{
		check_flag(f, i, args);
		check_width(f, i, args, pa);
		check_precision(f, i, args, pa);
	}
	conversion(f[*i], args);
}

void	check_flag(char *f, int *i, t_args *args)
{
	while (f[*i] && (f[*i] == '0' || f[*i] == '-'))
	{
		if (f[*i] == '-')
		{
			MINUS = 1;
			ZERO = 0;
		}
		if (f[*i] == '0' && MINUS == 0)
			ZERO = 1;
		*i += 1;
	}
}

void	check_width(char *f, int *i, t_args *args, va_list pa)
{
	while (f[*i] && (f[*i] == '*' || (f[*i] >= '0' && f[*i] <= '9')))
	{
		if (f[*i] == '*')
		{
			WIDTH = va_arg(pa, int);
			*i += 1;
		}
		else
			while (f[*i] >= '0' && f[*i] <= '9')
			{
				WIDTH = WIDTH * 10 + f[*i] - '0';
				*i += 1;
			}
	}
}

void	check_precision(char *f, int *i, t_args *args, va_list pa)
{
	char	*ptr;

	ptr = f;
	PRECISION = 0;
	if (f[*i] != '.')
		return ;
	*i += 1;
	IFPREC = 1;
	while (f[*i] && (f[*i] == '-' || f[*i] == '*'
				|| (f[*i] >= '0' && f[*i] <= '9')))
	{
		if (f[*i] == '*')
		{
			STAR = 1;
			PRECISION = va_arg(pa, int);
			*i += 1;
		}
		else
		{
			ptr += *i;
			PRECISION = ft_atoi(ptr);
			while ((f[*i] != '\0' && f[*i] > 47 && f[*i] < 58) || f[*i] == '-')
				*i += 1;
		}
	}
}

void	conversion(char conv, t_args *args)
{
	if (conv == 'd' || conv == 's' || conv == 'p' || conv == 'i' || conv == 'u'
			|| conv == 'X' || conv == 'x' || conv == 'c' || conv == '%')
		CONV = conv;
	else
		CONV = -1;
}
