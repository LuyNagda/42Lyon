/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:30:10 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 10:29:01 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *str, int c, unsigned int n)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	temp = (char *)str;
	while (temp[i] != c)
		i++;
	return (temp[i]);
}
