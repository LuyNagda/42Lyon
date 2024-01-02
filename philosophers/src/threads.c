/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:10:56 by lunagda           #+#    #+#             */
/*   Updated: 2024/01/02 20:03:35 by luynagda         ###   ########.fr       */
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
		ft_msleep(0.9 * philo->time_to_eat);
	while (!dead(philo))
	{
		if (dead(philo))
			return (NULL);
		eat(philo);
		if (dead(philo))
			return (NULL);
		snooze(philo);
		if (dead(philo))
			return (NULL);
		think(philo);
		if (dead(philo))
			return (NULL);
	}
	return (pointer);
}

void	create_threads(t_prog *prog, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	observer;

	i = 0;
	if (pthread_create(&observer, NULL, &monitor, prog->philos) != 0)
		destroy_all("Error while creating thread.", prog, forks);
	while (i < prog->philos[0].num_of_philos)
	{
		if (pthread_create(&prog->philos[i].thread, NULL,
				&philo_routine, &prog->philos[i]) != 0)
			destroy_all("Error while creating thread.", prog, forks);
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		destroy_all("Error while creating thread.", prog, forks);
	i = 0;
	while (i < prog->philos[0].num_of_philos)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != 0)
			destroy_all("Error while creating thread.", prog, forks);
		i++;
	}
}
