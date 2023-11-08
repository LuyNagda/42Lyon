/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:31:19 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/08 14:08:37 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	i--;
	while (s[i] && s[i] != (unsigned char)c)
		i--;
	if (i < 0)
		return (NULL);
	return ((char *)&s[i]);
}
