/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:18:11 by lunagda           #+#    #+#             */
/*   Updated: 2024/01/02 19:56:24 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *s)
{
	int	i;
	int	n;
	int	negative;

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

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(char *msg, t_philo *philo, int id)
{
	size_t	time;

	time = get_current_time() - philo->start_time;
	if (!dead(philo))
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%06zu %d %s\n", time, id, msg);
		pthread_mutex_unlock(philo->write_lock);
	}
}

int	ft_msleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(1000);
	return (0);
}

void	destroy_all(char *str, t_prog *prog, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
		printf("%s\n", str);
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->write_lock);
	while (i < prog->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
