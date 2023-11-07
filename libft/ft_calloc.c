/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:44:30 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 10:28:43 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(unsigned int nitems, unsigned int size)
{
	char	*p;

	if (nitems == 0 || size == 0)
		return (NULL);
	else
	{
		p = malloc(nitems * size);
		ft_bzero(p, nitems * size);
		return (p);
	}
}
