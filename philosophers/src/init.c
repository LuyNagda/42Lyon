/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:23:55 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/18 16:52:36 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_prog(t_prog *prog, int argc, char **argv)
{
	prog->philo->num_of_philos = ft_atoi(argv[1]);
	prog->philo->time_to_die = ft_atoi(argv[2]);
	prog->philo->time_to_eat = ft_atoi(argv[3]);
	prog->philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		prog->philo->time_to_sleep = ft_atoi(argv[5]);
}
