/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:33:55 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 12:58:11 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*temp1;
	char	*temp2;

	i = 0;
	temp1 = (char *)s1;
	temp2 = (char *)s2;
	while (temp1[i] && temp2[i] && temp1[i] == temp2[i])
		i++;
	return (temp1[i] - temp2[i]);
}
