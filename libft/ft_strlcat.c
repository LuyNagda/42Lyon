/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:14:16 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 13:08:10 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	result;

	result = (size_t)ft_strlen((char *)src);
	len = (size_t)ft_strlen(dst);
	i = 0;
	if (size < len)
		result += size;
	else
		result += len;
	while (src[i] && len + i < size - 1 && size != '\0')
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (result);
}
