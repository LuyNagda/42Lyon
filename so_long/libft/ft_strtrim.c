/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:35:34 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/09 10:46:06 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trg;
	int		start;
	int		stop;
	int		len;

	len = ft_strlen((char *)s1);
	start = 0;
	stop = len - 1;
	while (s1[start] && (is_set(s1[start], set) == 1))
		start++;
	while (is_set(s1[stop], set) == 1)
		stop--;
	len = stop - start + 1;
	trg = ft_substr(s1, start, len);
	return (trg);
}
