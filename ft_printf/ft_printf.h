/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:25:36 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/02 18:25:37 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_col
{
	int	minus;
	int	zero;
	int	precision;
	int	width;
	int	plus;
	int	space;
	int	hash;
	int	len;
}	t_col;

int		ft_printf(const char *format, ...);

void	ft_putptr(void *ptr, t_col *col1);
void	ft_puthex(unsigned long int i, t_col *col1, int is_capital);
void	ft_putunsigndec(unsigned int i, t_col *col1);
void	ft_putstr(char *s, t_col *col1);
void	ft_putchar_flags(char c, t_col *col1);
void	ft_putchar(char c);
void	ft_putnbr(int n, t_col *col1);

//utils
void	ft_print_col(t_col col1);
int		ft_lenHelper(int x);
void	ft_fill_spaces(int x);
#endif