/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:57:27 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/02 18:20:00 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_minus(const char *str, int len)
{
	int	cnt;

	cnt = 0;
	while ((str[cnt] >= 9 && str[cnt] <= 13) || str[cnt] == 32)
		cnt++;
	if (cnt < len - 1)
	{
		if (str[cnt] == '-' && (str[cnt + 1] >= '0' && str[cnt + 1] <= '9'))
			return (-1);
		if (str[cnt] == '+' && (str[cnt + 1] >= '0' && str[cnt + 1] <= '9'))
			return (1);
	}
	if (str[cnt] >= '0' && str[cnt] <= '9')
		return (1);
	return (0);
}

static long long int	print_numb(const char *str)
{
	int				cnt;
	long long int	nb;

	nb = 0;
	cnt = 0;
	while (str[cnt] < '0')
	{
		cnt++;
	}
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		nb = nb * 10 + str[cnt] - 48;
		cnt++;
	}
	return (nb);
}

long long int	ft_atoll(const char *str)
{
	int				minus;
	long long int	nb;
	int				len;

	if (str[0] == '\0')
	{
		return (0);
	}
	len = ft_strlen(str);
	minus = check_minus(str, len);
	nb = print_numb(str);
	return (minus * nb);
}
