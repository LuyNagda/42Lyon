/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:13:15 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/10 15:30:20 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;

	va_start(ptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar(va_arg(ptr, int));
			if (str[i] == 's')
				ft_putstr(va_arg(ptr, char *));
			if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr(va_arg(ptr, int));
			if (str[i] == 'x' || str[i] == 'X' || str[i] == 'p')
				ft_print_hexa(va_arg(ptr, long int), str[i]);
			if (str[i] == '%')
				ft_putchar('%');
		}
		else
			ft_putchar(str[i]);
	}
}
