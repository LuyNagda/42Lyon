/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:36:22 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/10 17:47:01 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0 || ft_strlen((char *)big) < ft_strlen((char *)little))
		return (NULL);
	while (big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && little[j] && (i + j) <= len)
				j++;
			if ((i + j) > len)
				return (NULL);
			if (little[j] == '\0' || j == len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
