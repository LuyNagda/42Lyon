/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:41:03 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/11 15:48:40 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr_pt(char res[16], int len)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	count += ft_putstr("0x");
	while (res[len])
	{
		count += ft_putchar(hex[res[len] - 48]);
		len--;
	}
	return (count);
}

int	ft_print_ptr(long int n)
{
	char			res[20];
	int				i;

	i = 0;
	if (n == LONG_MIN)
		return (ft_putstr("0x8000000000000000"));
	if ((unsigned long int)n == ULONG_MAX)
		return (ft_putstr("0xffffffffffffffff"));
	if (n == 0)
		return (ft_putstr("(nil)"));
	if (n < 0)
		n = -n;
	while (n)
	{
		res[i++] = (n % 16) + 48;
		n /= 16;
	}
	return (ft_print_ptr_pt(res, --i));
}
