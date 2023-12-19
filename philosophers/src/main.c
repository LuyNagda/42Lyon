/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:17 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/19 16:45:08 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_prog			prog;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		return (printf("There has to be 4 or 5 arguments.\n"), 1);
	if (ft_check_args(argv) == 1)
		return (1);
	init_prog(&prog, philos);
	init_forks(forks, argv);
	init_philos(philos, &prog, forks, argv);
	create_threads(&prog);
	return (0);
}
