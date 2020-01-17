/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 00:50:33 by akhalid           #+#    #+#             */
/*   Updated: 2020/01/17 12:12:44 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# define MINUS args->minus
# define ZERO args->zero
# define IFPREC args->ifprec
# define STAR args->star
# define PTR args->ptr
# define CONV args->conv
# define WIDTH args->width
# define PRECISION args->precision
# define RES args->res
# define LEN args->len

typedef	struct		s_args
{
	int		minus;
	int		zero;
	int		ifprec;
	int		star;
	int		ptr;
	char	conv;
	int		width;
	int		precision;
	int		res;
	int		len;
}					t_args;

int					ft_printf(const char *format, ...);
int					printf_(char *format, va_list pa);
void				print(int start, int i, char *format);
void				zero_args(t_args *args);
void				format_handler(char *f, int *i, t_args *args, va_list pa);
void				check_flag(char *f, int *i, t_args *args);
void				check_width(char *f, int *i, t_args *args, va_list pa);
void				check_precision(char *f, int *i, t_args *args, va_list pa);
void				conversion(char conv, t_args *args);
void				print_format(t_args *args, va_list pa);
void				ft_putcharpr(char c, t_args *args);
void				print_perc(t_args *args);
void				printf_parse(t_args *args);
void				print_string(t_args *args, va_list pa);
int					ft_strlen(char *str);
void				print_char(t_args *args, va_list pa);
void				print_int(t_args *args, va_list pa);
void				ft_putnbrpr(long int nb, t_args *args);
void				print_unsigned_int(t_args *args, va_list pa);
void				parse_unsigned_int(t_args *args);
void				print_pointer(t_args *args, va_list pa);
void				parse_ptr(t_args *args);
char				*convert(t_args *args, long long int nb);
char				*ft_convert_hex(unsigned long int nb, int type);
void				*ft_bzero(size_t size);
void				*ft_memset(void *str, int c, size_t size);
char				*ft_strrev(char *str);
char				*ft_strnew(size_t size);
char				*ft_itoa(long int nbr);
long	long	int	assign_value(t_args *args, va_list pa);
void				ft_putstrpr(char *s, t_args *args);
int					ft_strcmp(char *s1, char *s2);
int					absolute(int i);
int					ft_atoi(const char *str);

#endif
