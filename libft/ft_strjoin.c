/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:15:33 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/07 11:34:43 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*trg;
	int		i;
	int		s1_len;
	int		s2_len;

	i = 0;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	trg = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!trg)
		return (NULL);
	while (s1[i])
		trg[i++] = s1[i];
	i = 0;
	while (s2[i])
		trg[s1_len++] = s2[i++];
	trg[s1_len] = '\0';
	return (trg);
}
