/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:44:09 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/27 08:17:48 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hexnbr(unsigned long int i, int is_capital)
{
	if ((i % 16) < 10)
	{
		i = (i % 16) + '0';
		write(1, &i, 1);
	}
	else if (is_capital)
	{
		i = (i % 16) + 'A' - 10;
		write(1, &i, 1);
	}
	else
	{
		i = (i % 16) + 'a' - 10;
		write(1, &i, 1);
	}
}

void	ft_puthex(unsigned long int i, t_col *col1, int is_capital)
{
	if (i == 0)
	{
		col1->len = col1-> len + 1;
		write(1, "0", 1);
	}
	else if (i < 16)
	{
		col1->len = col1-> len + 1;
		put_hexnbr(i, is_capital);
	}
	else
	{
		col1->len = col1-> len + 1;
		ft_puthex(i / 16, col1, is_capital);
		put_hexnbr(i, is_capital);
	}
}
