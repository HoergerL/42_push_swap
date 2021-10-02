/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsigndec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:44:16 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/27 08:17:51 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigndec(unsigned int i, t_col *col1)
{
	if (i == 0)
	{
		write(1, "0", 1);
		col1->len = col1-> len + 1;
	}
	else if (i < 10)
	{
		i = i + '0';
		write(1, &i, 1);
		col1->len = col1-> len + 1;
	}
	else
	{
		ft_putunsigndec(i / 10, col1);
		i = (i % 10) + '0';
		write(1, &i, 1);
		col1->len = col1-> len + 1;
	}
}
