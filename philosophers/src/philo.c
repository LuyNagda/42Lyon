/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:17 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/18 16:52:04 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_prog			prog;
	t_philo			philo[200];
	pthread_mutex_t	mutex[200];

	if (argc != 4 && argc != 5)
		return (printf("There has to be 4 or 5 arguments.\n"));
	if (ft_check_args(argv) == 1)
		return (1);
	init_prog(&prog, argc, argv);
	return (0);
}
