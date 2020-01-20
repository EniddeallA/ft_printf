/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 04:15:46 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/20 08:45:13 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_bzero(size_t size)
{
	void	*tab;

	if (!(tab = (void *)malloc(size)))
		return (NULL);
	ft_memset(tab, '\0', size);
	return (tab);
}

void	*ft_memset(void *str, int c, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = str;
	while (i < size)
		tmp[i++] = c;
	return (str);
}

char	*ft_strnew(size_t size)
{
	char	*tab;

	if (!(tab = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(tab, '\0', size + 1);
	return (tab);
}
