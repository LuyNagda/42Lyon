/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:50:37 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 10:28:46 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argument)
{
	if ((argument >= "a" && argument <= "z") || 
		(argument >= "A" && argument <= "Z") || 
		(argument >= 0 && argument <= 9))
		return (1);
	else
		return (0);
}
