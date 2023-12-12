/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:19:26 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/11 13:47:08 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(const char *s, int c)
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

char	*ft_strddup(const char *src)
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

char	*ft_strnddup(char *src, int start, int stop)
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
	len = ft_strlen(dst) + ft_strlen((char *)src);
	i = 0;
	trg = (char *)malloc((len + 1) * sizeof(char));
	while (dst[i])
	{
		trg[i] = dst[i];
		i++;
	}
	trg[i] = '\0';
	i = 0;
	free(dst);
	while (src[i])
	{
		trg[dst_len + i] = src[i];
		i++;
	}
	trg[dst_len + i] = '\0';
	return (trg);
}