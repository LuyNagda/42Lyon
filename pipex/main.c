/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:50:33 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/07 17:55:00 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	f1;
	int f2;

	if (argc != 5)
		msg("There are less arguments than expected.");
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		perror(argv[1]);
	if (f2 < 0)
		error_msg(argv[4]);
	pipex(f1, f2, argv, env);
	return (0);
}
