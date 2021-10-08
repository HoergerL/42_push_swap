/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:28:31 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/08 17:06:54 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> 

int	ft_intchr(int *haystack, int size_haystack, int needle)
{
	int	i;

	i = 0;
	while (i < size_haystack)
	{
		if (haystack[i] == needle)
			return (i);
		i++;
	}
	return (-1);
}
