/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 11:36:37 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/24 09:48:13 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*src2;
	char	*dest2;

	src2 = (char *) src;
	dest2 = (char *) dst;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (src >= dst)
	{
		while (i++ < len)
			dest2[i - 1] = src2[i - 1];
	}
	else
	{
		i = len;
		while (i > 0)
		{
			dest2[i - 1] = src2[i - 1];
			i--;
		}
	}
	return (dst);
}
