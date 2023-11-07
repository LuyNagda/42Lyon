/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:14:16 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 10:30:54 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	result;

	result = (unsigned int)ft_strlen(src);
	len = (unsigned int)ft_strlen(dest);
	i = 0;
	if (size < len)
		result += size;
	else
		result += len;
	while (src[i] && len + i < size - 1 && size != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (result);
}
