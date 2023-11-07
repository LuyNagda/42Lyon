/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:43:46 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 10:30:19 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*trg;
	int		i;

	i = 0;
	trg = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	while (src[i])
	{
		trg[i] = src[i];
		i++;
	}
	trg[i] = '\0';
	return (trg);
}
