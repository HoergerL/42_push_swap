/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:48:44 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/21 11:05:45 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	cnt;
	unsigned char	*s1x;
	unsigned char	*s2x;

	s1x = (unsigned char *) s1;
	s2x = (unsigned char *) s2;
	cnt = 0;
	while ((s1x[cnt] != '\0' || s2x[cnt] != '\0') && cnt < n)
	{
		if (s1x[cnt] != s2x[cnt])
		{
			return (s1x[cnt] - s2x[cnt]);
		}
		cnt++;
	}
	return (0);
}
