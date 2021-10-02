/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 11:23:39 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/20 15:46:46 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cnt;
	char			*str;
	unsigned char	var;

	cnt = 0;
	str = (char *) b;
	var = (unsigned char) c;
	while (cnt < len)
	{
		str[cnt] = var;
		cnt++;
	}
	return (b);
}
