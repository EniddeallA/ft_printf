/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 04:15:46 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/04 07:20:06 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	int	i;
	int	temp;
	int	k;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	k = 0;
	while (k < i - 1)
	{
		temp = str[i - 1];
		str[i - 1] = str[k];
		str[k] = temp;
		i--;
		k++;
	}
	return (str);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s2 == '\0')
			return (1);
		else if (*s1 > *s2)
			return (1);
		else if (*s1 < *s2)
			return (-1);
		s1++;
		s2++;
	}
	if (*s2 != 0)
		return (-1);
	else
		return (0);
}

char	*ft_convert_hex(unsigned long int nb, int type)
{
	char	*print;
	int		i;

	i = 0;
	print = ft_bzero(21);
	if (nb == 0)
		print[i] = '0';
	if (type == 0)
		while (nb != 0)
		{
			print[i++] = "0123456789abcdef"[nb % 16];
			nb /= 16;
		}
	else
		while (nb != 0)
		{
			print[i++] = "0123456789ABCDEF"[nb % 16];
			nb /= 16;
		}
	return (ft_strrev(print));
}

char	*ft_itoa(int nbr)
{
	int			sign;
	int			count;
	char		*str;

	count = 1;
	sign = nbr;
	while (sign /= 10)
		count++;
	sign = nbr < 0 ? 1 : 0;
	count = nbr < 0 ? count += 1 : count;
	str = (char *)malloc(count + 1);
	str[count] = '\0';
	if (nbr == -2147483648)
		return ("-2147483648");
	if (sign == 1)
		str[0] = '-';
	nbr = nbr < 0 ? nbr *= -1 : nbr;
	while (--count >= sign)
	{
		str[count] = nbr >= 10 ? (nbr % 10) + 48 : nbr + 48;
		nbr /= 10;
	}
	return (str);
}

int		ft_atoi(const char *str)
{
	long res;
	long sign;

	res = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' ||
			*str == '\f' || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((unsigned long)__LONG_MAX__ < ((unsigned long)res * 10 + (*str -
						'0')) && sign == 1)
			return (-1);
		else if ((unsigned long)__LONG_MAX__ < ((unsigned long)res * 10 +
					(*str - '0')) && sign == -1)
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
