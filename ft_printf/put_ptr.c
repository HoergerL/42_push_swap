/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:43:59 by lhoerger          #+#    #+#             */
/*   Updated: 2021/08/27 08:17:42 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, t_col *col1)
{
	write (1, "0x", 2);
	col1->len = col1->len + 2;
	ft_puthex((unsigned long) ptr, col1, 0);
}
