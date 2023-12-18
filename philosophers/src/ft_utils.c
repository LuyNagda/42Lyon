/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:18:11 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/18 16:45:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	ft_is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

size_t	ft_atoi(char *s)
{
	size_t	i;
	size_t	n;
	size_t	negative;
	
	i = 0;
	n = 0;
	negative = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			negative = -1;
		i++;
	}
	while (s[i])
	{
		n = n * 10;
		n += s[i] - '0';
		i++;
	}
	return (n * negative);
}

int	ft_check_args(char **argv)
{
	if (ft_is_number(argv[1]) == 0 || ft_is_number(argv[2]) == 0 || 
		ft_is_number(argv[3]) == 0 || ft_is_number(argv[4]) == 0)
	{
		printf("The arguments have to be numbers.\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[2]) == 0 || 
		ft_atoi(argv[3]) == 0 || ft_atoi(argv[4]) == 0)
	{
		printf("The arguments have to be 1 or above.\n");
		return (1);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		printf("The number of philosophers has to be 200 or below.\n");
		return (1);
	}
	return (0);
}
