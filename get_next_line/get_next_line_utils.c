/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:19:26 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/15 17:06:59 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (1);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == '\0' && c != '\0' && c != 1024)
		return (-1);
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strndup(char *src, int start, int stop)
{
	char	*trg;
	int		i;

	i = 0;
	trg = (char *)malloc((stop - start + 1) * sizeof(char));
	if (!trg)
		return (NULL);
	while (src[start] && start < stop)
		trg[i++] = src[start++];
	trg[i] = '\0';
	return (trg);
}

char	*ft_strcatdup(char *dst, const char *src)
{
	size_t	len;
	size_t	dst_len;
	size_t	i;
	char	*trg;

	dst_len = ft_strlen(dst);
	len = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	trg = (char *)malloc((len + 2) * sizeof(char));
	trg = ft_strcpy(trg, dst);
	free(dst);
	while (src[i])
	{
		trg[dst_len + i] = src[i];
		i++;
	}
	trg[dst_len + i] = '\0';
	return (trg);
}
