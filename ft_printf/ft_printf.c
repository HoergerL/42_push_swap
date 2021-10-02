/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:13:05 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/27 09:58:01 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void	ft_find_conversion(char s, t_col *col1, va_list args)
{
	if (s == 'c')
		ft_putchar_flags(va_arg(args, int), col1);
	else if (s == 's')
		ft_putstr(va_arg(args, char *), col1);
	else if (s == 'p')
		ft_putptr(va_arg(args, void *), col1);
	else if (s == 'i' || s == 'd')
		ft_putnbr(va_arg(args, int), col1);
	else if (s == 'u')
		ft_putunsigndec(va_arg(args, unsigned int), col1);
	else if (s == 'x')
		ft_puthex((unsigned long int) va_arg(args, unsigned int), col1, 0);
	else if (s == 'X')
		ft_puthex(va_arg(args, unsigned int), col1, 1);
	else if (s == '%')
	{
		ft_putchar('%');
		col1->len = col1-> len + 1;
	}
}

void	ft_reset_col(t_col *col1)
{
	col1->minus = 0;
	col1->zero = 0;
	col1->precision = 0;
	col1->width = 0;
	col1->plus = 0;
	col1->space = 0;
	col1->hash = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_col	col1;

	va_start(args, format);
	col1.len = 0;
	while (*format != '\0')
	{	
		if (*format == '%')
		{
			format++;
			ft_reset_col(&col1);
			ft_find_conversion(*format, &col1, args);
			format++;
		}
		else
		{
			ft_putchar(*format);
			format++;
			col1.len += 1;
		}
	}
	va_end(args);
	return (col1.len);
}
