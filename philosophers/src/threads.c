/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:10:56 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/19 16:32:40 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	return (pthread_mutex_unlock(philo->dead_lock), 0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead(philo))
	{
		eat(philo);
		snooze(philo);
		think(philo);
	}
}

void	create_threads(t_prog *prog)
{
	int			i;
	pthread_t	observer;

	i = 0;
	if (pthread_create(&observer, NULL, &monitor, prog->philos) != 0)
		exit(0);
	while (i < prog->philos[0].num_of_philos)
	{
		if (pthread_create(&prog->philos[i].thread, NULL,
				&philo_routine, &prog->philos[i]) != 0)
			exit(0);
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		exit(0);
	i = 0;
	while (i < prog->philos[0].num_of_philos)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != 0)
			exit(0);
		i++;
	}
}
