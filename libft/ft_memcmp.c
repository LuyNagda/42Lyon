/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:33:55 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/09 10:22:21 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	i = 0;
	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && temp1[i] == temp2[i])
		i++;
	if (i == n)
		return (0);
	return (temp1[i] - temp2[i]);
}
