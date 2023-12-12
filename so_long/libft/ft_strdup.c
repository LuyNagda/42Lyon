/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:43:46 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 13:04:25 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*trg;
	int		i;

	i = 0;
	trg = (char *)malloc(ft_strlen((char *)src) * sizeof(char) + 1);
	if (!trg)
		return (NULL);
	while (src[i])
	{
		trg[i] = src[i];
		i++;
	}
	trg[i] = '\0';
	return (trg);
}
