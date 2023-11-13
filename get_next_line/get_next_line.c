/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:28 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/13 17:44:48 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			c;
	static char	buffer[BUFFER_SIZE];
	char		*str;

	c = -1;
	if (fd == -1)
		return (NULL);
	while (c != 0 && (strchr(str, '\n') == 0))
		c = read(fd, buffer, BUFFER_SIZE);
	if (c != 0)
		buffer[c++] = '\n';
	buffer[c] = '\0';
	return (buffer);
}
