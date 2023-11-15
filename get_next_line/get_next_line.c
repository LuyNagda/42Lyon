/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:45:23 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/15 17:57:03 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	char	*trg;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	trg = (char *)malloc(ft_strlen((char *)src) * sizeof(char) + 1);
	if (!trg)
		return (NULL);
	while (src[i])
	{
		trg[i] = src[i];
		i++;
	}
	trg[i] = '\0';
	return (trg);
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

char	*get_next_line(int fd)
{
	int			c;
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	c = -1;
	str = NULL;
	if (buffer[0] != '\0')
	{
		int	i = 0;
		while (buffer[i] != '\n')
			i++;
		if (buffer[++i] != '\0')
			str = ft_strndup(buffer, ft_strchr(buffer, '\n') + 1, ft_strlen(buffer));
	}
	while (c != 0 && ft_strchr(str, '\n') == -1)
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c == 0)
		{
			buffer[0] = '\0';
			str = ft_strcut(str);
		}
		buffer[c] = '\0';
		if (c != 0)
		{
			if (!str)
				str = ft_strdup(buffer);
			else
				str = ft_strcatdup(str, buffer);
		}
	}
	return (ft_strcut(str));
}
//#include <fcntl.h>
//#include <stdio.h>
//int	main(void)
//{
//	int fd = open("blank.txt", O_RDONLY);
//	char	*temp;

//	temp = get_next_line(fd);
//	printf("%s", temp);
//	free(temp);
//	temp = get_next_line(fd);
//	printf("%s", temp);
//	free(temp);
//	temp = get_next_line(fd);
//	printf("%s", temp);
//	free(temp);
	
//}