/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:44:53 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/13 11:31:26 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp1;
	char	*temp2;

	if (!dest && !src)
		return (NULL);
	temp1 = (char *)dest;
	temp2 = (char *)src;
	if (src > dest)
		ft_memcpy(dest, src, n);
	else if (src < dest)
	{
		while (n > 0)
		{
			temp1[n - 1] = temp2[n - 1];
			n--;
		}
	}
	return (dest);
}
