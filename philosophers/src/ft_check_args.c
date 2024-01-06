/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:59:42 by lunagda           #+#    #+#             */
/*   Updated: 2024/01/06 21:41:30 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_number(char *s)
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

int	check_for_num(char **argv)
{
	if (ft_is_number(argv[1]) == 0)
		return (printf("Number of philosophers has to be a number.\n"), 1);
	if (ft_atoi(argv[1]) < 0)
		return (printf("Number of philosophers cannot be a negative number.\n")
			, 1);
	if (ft_is_number(argv[2]) == 0)
		return (printf("Time to die has to be a number (in ms).\n"), 1);
	if (ft_atoi(argv[2]) < 0)
		return (printf("Time to die has to be a positive number (in ms).\n")
			, 1);
	if (ft_is_number(argv[3]) == 0)
		return (printf("Time to eat has to be a number (in ms).\n"), 1);
	if (ft_atoi(argv[3]) < 0)
		return (printf("Time to eat has to be a positive number (in ms).\n")
			, 1);
	if (ft_is_number(argv[4]) == 0)
		return (printf("Time to sleep has to be a number (in ms).\n"), 1);
	if (ft_atoi(argv[4]) < 0)
		return (printf("Time to sleep has to be a positive number (in ms).\n")
			, 1);
	return (0);
}

int	ft_check_args(char **argv)
{
	if (check_for_num(argv) == 1)
		return (1);
	if (argv[5])
	{
		if (ft_is_number(argv[5]) == 0)
			return (printf("Number of meals has to be a number.\n"), 1);
		if (ft_atoi(argv[5]) < 0)
			return (printf("Number of meals has to be a positive number (in ms).\n")
				, 1);
	}
	if (ft_atoi(argv[1]) > PHILO_MAX)
		return (printf("The number of philosophers is more than expected.\n")
			, 1);
	return (0);
}
