/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:50:37 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 11:14:13 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argument)
{
	if ((argument >= "a" && argument <= "z")
		|| (argument >= "A" && argument <= "Z")
		|| (argument >= 0 && argument <= 9))
		return (1);
	else
		return (0);
}
