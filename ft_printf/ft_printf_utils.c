/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:54:57 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/27 08:16:46 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_col(t_col col1)
{
	ft_printf("\n\ncol:\n");
	ft_printf("minus: %i\n", col1.minus);
	ft_printf("zero: %i\n", col1.zero);
	ft_printf("precision: %i\n", col1.precision);
	ft_printf("width: %i\n", col1.width);
	ft_printf("plus: %i\n", col1.plus);
	ft_printf("space: %i\n", col1.space);
	ft_printf("hash: %i\n", col1.hash);
	ft_printf("len: %i\n\n\n", col1.len);
}

int	ft_lenHelper(int x)
{
	if (x >= 1000000000)
		return (10);
	if (x >= 100000000)
		return (9);
	if (x >= 10000000)
		return (8);
	if (x >= 1000000)
		return (7);
	if (x >= 100000)
		return (6);
	if (x >= 10000)
		return (5);
	if (x >= 1000)
		return (4);
	if (x >= 100)
		return (3);
	if (x >= 10)
		return (2);
	return (1);
}

void	ft_fill_spaces(int x)
{
	while ((x) - 1 > 0)
	{
		(x)--;
		ft_putchar(' ');
	}
}
