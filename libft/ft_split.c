/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:50:35 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/25 12:26:49 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);

static int	ft_create_resulstr(char ***resulstr, char *s)
{
	*resulstr = malloc(sizeof(char *) * ft_strlen(s) + 1);
	if (!*resulstr)
		return (0);
	return (1);
}

static void	ft_set_vars(int *i, int *j, int *l)
{
	*i = 0;
	*j = 0;
	*l = 0;
}

static int	ft_jump_to_end(char *s, int i)
{
	if (s[i])
		i++;
	return (i);
}

static int	ft_jump_to_word_end(char *s, char c, int i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**resulstr;
	int		i;
	int		j;
	int		l;

	ft_set_vars(&i, &j, &l);
	if (!s || !ft_create_resulstr(&resulstr, (char *) s))
		return (0);
	while (s[i])
	{
		i = ft_jump_to_word_end((char *)s, c, i);
		if (s[i])
		{
			j = i;
			while (s[i] != c && s[i])
				i++;
			resulstr[l] = malloc(i - j + 1);
			ft_memcpy(resulstr[l], &(s[j]), i - j);
			resulstr[l][i - j] = 0;
			l++;
		}
		i = ft_jump_to_end((char *) s, i);
	}
	resulstr[l] = 0;
	return (resulstr);
}
