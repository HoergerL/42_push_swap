/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:53:03 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/24 09:51:58 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s_res;

	i = 0;
	if (!s)
		return (0);
	s_res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s_res)
		return (0);
	while (s[i])
	{
		s_res[i] = f(i, s[i]);
		i++;
	}
	s_res[i] = '\0';
	return (s_res);
}
