/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:35:15 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 13:25:17 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*trg;
	size_t	end;
	size_t	i;

	i = 0;
	end = start + len;
	trg = (char *)malloc(len * sizeof(char) + 1);
	if (!trg)
		return (NULL);
	while (start < end)
	{
		trg[i] = s[start];
		start++;
		i++;
	}
	trg[i] = '\0';
	return (trg);
}
