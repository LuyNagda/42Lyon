/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:29:05 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/11 14:35:26 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	long long int	nb;

	nb = n;
	if (nb > 9)
	{
		ft_print_unsigned(nb / 10);
		ft_print_unsigned(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
	return (ft_num_len(nb));
}
