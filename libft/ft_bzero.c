/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:36:00 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 10:28:38 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *dst, int n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)dst;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
	return (dst);
}
