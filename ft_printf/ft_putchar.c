/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:39:07 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/27 08:17:22 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_flags(char c, t_col *col1)
{
	if (col1->width)
	{
		col1->len = col1->len + col1->width;
		if (col1->minus)
		{
			write(1, &c, 1);
			ft_fill_spaces(col1->width);
		}
		if (!(col1->minus))
		{
			ft_fill_spaces(col1->width);
			write(1, &c, 1);
		}
	}
	else
	{
		col1->len = col1->len + 1;
		write(1, &c, 1);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
