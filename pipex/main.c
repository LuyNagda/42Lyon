/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:50:33 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/08 17:25:45 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	vars;

	if (argc != 5)
	{
		msg("There are less arguments than expected.");
		exit(EXIT_FAILURE);
	}
	vars.f1 = open(argv[1], O_RDONLY);
	vars.f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars.f1 < 0)
		joint_error_msg(argv[1]);
	if (vars.f2 < 0)
	{
		joint_error_msg(argv[4]);
		exit(EXIT_FAILURE);
	}
	vars.paths = parsing_for_path(env);
	vars.cmd1 = ft_split(argv[2], ' ');
	vars.cmd2 = ft_split(argv[3], ' ');
	vars.path1 = get_path(vars.paths, vars.cmd1);
	vars.path2 = get_path(vars.paths, vars.cmd2);
	ft_free(vars.paths);
	pipex(vars);
	return (0);
}
