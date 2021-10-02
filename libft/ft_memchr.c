/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:46:31 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/21 10:55:20 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cnt;
	unsigned char	var;
	unsigned char	*s_cpy;

	cnt = 0;
	var = (unsigned int) c;
	s_cpy = (unsigned char *) s;
	while (cnt < n)
	{
		if (s_cpy[cnt] == var)
			return ((void *) &s_cpy[cnt]);
		cnt++;
	}
	return (NULL);
}
