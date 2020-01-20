/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 04:15:46 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/20 08:44:56 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

void	ft_putcharpr(char c, t_args *args)
{
	write(1, &c, 1);
	RES += 1;
}

void	ft_putnbrpr(long int nb, t_args *args)
{
	if (nb < 0)
	{
		ft_putcharpr('-', args);
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_putcharpr(nb + 48, args);
		return ;
	}
	ft_putnbrpr(nb / 10, args);
	ft_putcharpr(nb % 10 + 48, args);
}

void	ft_putstrpr(char *s, t_args *args)
{
	int	i;

	i = 0;
	if (ft_strcmp(s, "0x") == 0)
	{
		if (PTR)
			while (s[i])
				ft_putcharpr(s[i++], args);
		PTR = 0;
	}
	else
		while (s[i])
			ft_putcharpr(s[i++], args);
}
