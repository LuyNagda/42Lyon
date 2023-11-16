/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:45:23 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/16 22:52:36 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}

char	*ft_strcut(char *str)
{
	char	*trg;

	if (ft_strchr(str, '\n') != -1)
	{
		trg = ft_strndup(str, 0, ft_strchr(str, '\n') + 1);
	}
	else
		trg = ft_strdup(str);
	free(str);
	return (trg);
}

void	offset_buffer(char (*buffer)[BUFFER_SIZE + 1])
{
	int	i;
	int	j;

	i = ft_strchr((const char *)buffer, '\n') + 1;
	j = 0;
	while (i < (BUFFER_SIZE + 1))
	{
		(*buffer)[j] = (*buffer)[i];
		j++;
		i++;
	}
}

char	*while_loop(int fd, char *str, char (*buffer)[BUFFER_SIZE + 1])
{
	int	c;

	c = -1;
	while (c != 0 && ft_strchr(str, '\n') == -1)
	{
		c = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[c] = '\0';
		if (c != 0)
		{
			if (!str)
				str = ft_strdup((*buffer));
			else
				str = ft_strcatdup(str, (*buffer));
		}
	}
	return (ft_strcut(str));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	str = NULL;
	if (buffer[0] != '\0')
	{
		i = 0;
		while (buffer[i] != '\n')
			i++;
		if (buffer[++i] != '\0')
		{
			str = ft_strndup(buffer, \
			ft_strchr(buffer, '\n') + 1, ft_strlen(buffer));
		}
		offset_buffer(&buffer);
	}
	str = while_loop(fd, str, &buffer);
	return (str);
}
