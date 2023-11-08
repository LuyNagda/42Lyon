/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:40:35 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/08 13:52:17 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_num_len(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	nb;
	int			len;
	char		*res;

	i = 0;
	nb = (long int)n;
	len = find_num_len(nb);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	else if (nb == 0)
		res[0] = '0';
	res[len--] = '\0';
	while (nb > 0)
	{
		res[len--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (res);
}
