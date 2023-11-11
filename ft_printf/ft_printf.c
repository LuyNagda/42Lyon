/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:13:15 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/11 15:02:48 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_formats(va_list ptr, const char *str, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(ptr, int));
	if (str[i] == 's')
		count += ft_putstr(va_arg(ptr, char *));
	if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(ptr, int));
	if (str[i] == 'x' || str[i] == 'X')
		count += ft_print_hexa(va_arg(ptr, unsigned int), str[i]);
	if (str[i] == 'p')
		count += ft_print_ptr(va_arg(ptr, long int));
	if (str[i] == '%')
		count += ft_putchar('%');
	if (str[i] == 'u')
		count += ft_print_unsigned(va_arg(ptr, unsigned int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ptr;

	va_start(ptr, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += print_formats(ptr, str, i);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
