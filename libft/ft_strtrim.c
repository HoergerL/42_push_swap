/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:30:15 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/25 12:15:52 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strfind(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == c)
			return (1);
		len--;
	}
	return (0);
}

static size_t	findstart(char const *str, char const *set)
{
	size_t	i;
	size_t	start;

	i = 0;
	while (str[i])
	{
		if (!(strfind(set, str[i])))
		{
			start = i;
			return (start);
		}
		i++;
	}
	return (0);
}

static size_t	findend(char const *str, char const *set)
{
	size_t	i;
	size_t	start;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (!(strfind(set, str[i])))
		{
			start = i;
			return (start);
		}
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*str2;

	i = 0;
	len = 0;
	if (!s1 || !set)
		return (0);
	len = findend(s1, set) - findstart(s1, set);
	str2 = malloc(sizeof(char) * len + 2);
	if (!str2)
		return (0);
	if (len == 0)
	{
		str2[0] = '\0';
		return (str2);
	}
	len = findstart(s1, set);
	while (len >= findstart(s1, set) && len <= findend(s1, set))
		str2[i++] = s1[len++];
	str2[i] = '\0';
	return (str2);
}
