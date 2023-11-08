/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:35:15 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/08 14:08:53 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*trg;
	size_t	end;
	size_t	i;
	size_t	string_len;

	string_len = ft_strlen(s);
	i = 0;
	if (len >= string_len)
		len = string_len - start;
	if (start > string_len)
		return (malloc(1));
	end = start + len;
	trg = (char *)malloc((len + 1) * sizeof(char));
	if (!trg)
		return (NULL);
	while (s[start] && start < end)
	{
		trg[i] = s[start];
		start++;
		i++;
	}
	trg[i] = '\0';
	return (trg);
}
