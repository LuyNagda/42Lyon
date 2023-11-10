/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:55:16 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/10 15:20:24 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_caps_nocaps(char *res, int c)
{
	char		*caps_hex;
	char		*hex;
	int			len;

	len = ft_strlen(res) - 1;
	caps_hex = "0123456789ABCDEF";
	hex = "0123456789abcdef";
	if (c == 'p')
		ft_putstr("0x");
	if (c == 'x' || c == 'p')
	{
		while (res[len])
		{
			ft_putchar(hex[res[len]]);
			len--;
		}
	}
	else
	{
		while (res[len])
		{
			ft_putchar(caps_hex[res[len]]);
			len--;
		}
	}
}

void	ft_print_hexa(long int nb, int c)
{
	char		res[16];
	int			i;

	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb)
	{
		res[i] = nb % 16;
		nb /= 16;
		i++;
	}
	ft_print_caps_nocaps(res, c);
}
