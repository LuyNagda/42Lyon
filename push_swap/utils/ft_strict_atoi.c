/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strict_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:13:24 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/28 20:18:37 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_strict_atoi(const char *str)
{
	int			i;
	long int	result;
	int			minus;

	i = 0;
	result = 0;
	minus = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * minus);
}
