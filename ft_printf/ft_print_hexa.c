/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:55:16 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/11 15:06:19 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_caps_nocaps(char *res, int c, int count, int len)
{
	char	*caps_hex;
	char	*hex;

	caps_hex = "0123456789ABCDEF";
	hex = "0123456789abcdef";
	if (c == 'x')
	{
		while (res[len])
		{
			count += ft_putchar(hex[res[len] - 48]);
			len--;
		}
	}
	else
	{
		while (res[len])
		{
			count += ft_putchar(caps_hex[res[len] - 48]);
			len--;
		}
	}
	return (count);
}

int	ft_print_hexa(unsigned int nb, int c)
{
	char	res[16];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (nb == 0)
	{
		count += ft_putchar('0');
		return (1);
	}
	while (nb)
	{
		res[i] = (nb % 16) + 48;
		nb /= 16;
		i++;
	}
	i--;
	return (ft_print_caps_nocaps(res, c, count, i));
}
