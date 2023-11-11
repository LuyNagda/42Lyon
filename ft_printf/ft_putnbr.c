/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:14:53 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/11 13:43:15 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(long int n)
{
	long int	nb;
	int			count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	if (nb == 0)
		return (1);
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
	return (ft_num_len((long int)n));
}
