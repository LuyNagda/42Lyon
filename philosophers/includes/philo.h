/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:02:45 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/20 15:24:05 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

# define PHILO_MAX 300

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			start_time;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
	int				num_of_philos;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_prog
{
	int				dead_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philos;
}	t_prog;

int		ft_atoi(char *s);
size_t	get_current_time(void);
int		ft_check_args(char **argv);
int		ft_msleep(size_t milliseconds);
void	print_message(char *msg, t_philo *philo, int id);
void	init_prog(t_prog *philo, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, char **argv);
void	init_philos(t_philo *philos, t_prog *prog,
			pthread_mutex_t *forks, char **argv);
int		dead(t_philo *philo);
void	think(t_philo *philo);
void	snooze(t_philo *philo);
void	eat(t_philo *philo);
void	*monitor(void *pointer);
void	create_threads(t_prog *prog, pthread_mutex_t *forks);
void	destroy_all(char *str, t_prog *prog, pthread_mutex_t *forks);

#endif