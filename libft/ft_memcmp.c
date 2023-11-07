/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:33:55 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 10:29:07 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *str1, void *str2, unsigned int n)
{
	unsigned int	i;
	char			*temp1;
	char			*temp2;

	i = 0;
	temp1 = (char *)str1;
	temp2 = (char *)str2;
	while (temp1[i] && temp2[i] && temp1[i] == temp2[i])
		i++;
	return (temp1[i] - temp2[i]);
}
