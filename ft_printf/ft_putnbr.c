/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:04:13 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/27 08:17:29 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"

int	ft_do_calculation(int n, t_col *col1, int new_n)
{
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		col1->len = col1-> len + 1;
	}
	if (n / 10 == 0)
	{
		n = n + 48;
		write(1, &n, 1);
		col1->len = col1-> len + 1;
		return (0);
	}
	new_n = n / 10;
	ft_putnbr(new_n, col1);
	n = (n % 10) + 48;
	write(1, &n, 1);
	col1->len = col1-> len + 1;
	return (1);
}

void	ft_putnbr(int n, t_col *col1)
{
	int	new_n;

	new_n = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", ft_strlen("-2147483648"));
		col1->len = col1-> len + 11;
		return ;
	}
	if (!(ft_do_calculation(n, col1, new_n)))
		return ;
}
