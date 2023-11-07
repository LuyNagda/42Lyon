/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:44:30 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 15:10:18 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	char	*p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	else
	{
		p = malloc(nmemb * size);
		if (!p)
			return (NULL);
		ft_bzero(p, nmemb * size);
		return (p);
	}
}
