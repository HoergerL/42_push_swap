/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:32:41 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/26 08:32:25 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	len_substr;

	if (!s)
		return (0);
	len_substr = ft_strlen(&s[start]);
	if (len_substr > len)
		len_substr = len;
	s2 = malloc(sizeof(char) * len + 1);
	if (len == 0 || start >= ft_strlen(s))
	{
		s2[0] = '\0';
		return (s2);
	}
	if (!s2)
		return (0);
	if (start > ft_strlen(s))
		return (s2);
	ft_memcpy(s2, &s[start], len_substr);
	s2[len_substr] = '\0';
	return (s2);
}
