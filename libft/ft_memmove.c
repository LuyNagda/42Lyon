/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:44:53 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 12:59:29 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp1;
	char	*temp2;

	i = 0;
	temp1 = (char *)dest;
	temp2 = (char *)src;
	if (src > dest)
	{
		while (i < n)
		{
			temp1[i] = temp2[i];
			i++;
		}
	}
	else if (src < dest)
	{
		while (n > 0)
		{
			temp1[n] = temp2[n];
			n--;
		}
	}
}
