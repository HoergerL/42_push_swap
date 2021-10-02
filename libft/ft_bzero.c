/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:46:04 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/20 15:46:16 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int		c;
	unsigned char		*t;

	c = 0;
	t = (unsigned char *)s;
	while (n > c)
	{
		t[c] = '\0';
		c++;
	}
}
