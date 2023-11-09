/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:13:15 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/09 14:09:11 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	va_start(ptr, str);

	int	i;

	i = 0;
	if (str[i] == '%')
	{
		i++;
		if (str[i] == 'c')
			ft_putchar(va_arg(ptr, int));
		if (str[i] == 's')
			ft_putstr(va_arg(ptr, char *));
		if (str[i] == 'd' || str[i] == 'i')
			ft_putnbr(va_arg(ptr, int));
		if (str[i] == 'x' || str[i] == 'X')
			ft_print_hexa(va_arg(ptr, int), str[i]);
		if (str[i] == '%')
			ft_putchar('%');
		if (str[i] == 'p')
			ft_print_pointer(va_arg(ptr, int));
	}
}
