/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:44:54 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/12 12:58:11 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SIZE_BUF 2

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*s_join;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_s1 = gnl_ft_strlen(s1);
	len_s2 = gnl_ft_strlen(s2);
	s_join = (char *)malloc(sizeof(*s1) * (len_s1 + len_s2) + 1);
	if (s_join == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		s_join[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		s_join[i++] = s2[j++];
	s_join[i] = '\0';
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (s_join);
}

char	*gnl_ft_strdup(char **s1)
{
	char	*s2;
	int		len;

	len = gnl_ft_strlen(*s1);
	s2 = gnl_ft_calloc(len + 1, sizeof(char));
	if (!s2)
		return (0);
	gnl_ft_memcpy((char *) s2, *s1, len + 1);
	free(*s1);
	*s1 = NULL;
	return (s2);
}

int	ft_get_next_line(char *buffer, int *j, char ***rest, char ***line)
{
	char	*chr;
	int		fndxst[2];
	char	*s;

	chr = NULL;
	fndxst[0] = SIZE_BUF;
	fndxst[1] = 2;
	if (*j == 0 || *j == -1)
		return (0);
	buffer[*j] = '\0';
	chr = gnl_ft_strchr(buffer, '\n');
	if (chr != NULL)
	{
		fndxst[1] = 1;
		fndxst[0] = chr - buffer + 1;
		*(*rest) = gnl_ft_substr(buffer, fndxst[0], SIZE_BUF - fndxst[1] + 1);
	}
	else if (*j < SIZE_BUF)
		fndxst[1] = 0;
	s = gnl_ft_substr(buffer, 0, fndxst[0]);
	if (*(*line))
		*(*line) = gnl_ft_strjoin(*(*line), s);
	else
		*(*line) = gnl_ft_strdup(&s);
	return (fndxst[1]);
}

int	ft_get_next_line_helper(char *buffer, int fd, char **rest, char **line)
{
	int	status;
	int	j;

	status = 2;
	j = SIZE_BUF;
	if (*rest != NULL && (*rest)[0] != 0)
	{
		 gnl_ft_memcpy(buffer, *rest, gnl_ft_strlen(*rest) + 1);
		 free(*rest);
		 *rest = NULL;
		 status = (ft_get_next_line(buffer, &j, &rest, &line));
	}
	while (status == 2 && j == SIZE_BUF)
	{
		j = read(fd, buffer, SIZE_BUF);
		status = ft_get_next_line(buffer, &j, &rest, &line);
		if (status != 2 && line == NULL)
		{
			free(buffer);
			buffer = NULL;
			return (0);
		}
	}
	return (status);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*rest[4096];
	char		*line;
	int			status;

	if (fd < 0 || SIZE_BUF <= 0)
		return (NULL);
	line = NULL;
	buffer = malloc(sizeof(char) * (SIZE_BUF + 1));
	if ((!buffer))
		return (NULL);
	status = ft_get_next_line_helper(buffer, fd, &rest[fd], &line);
	if (rest[fd] && status == 0)
		free(rest[fd]);
	free(buffer);
	buffer = NULL;
	return (line);
}
