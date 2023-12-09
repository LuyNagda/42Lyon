/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:50:33 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/09 16:05:30 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**initialize_commands(t_pipex vars)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	vars.commands = (char **)malloc((vars.argc - 2) * sizeof(char *));
	if (!vars.commands)
		exit(EXIT_FAILURE);
	while (i < (vars.argc - 1))
	{
		vars.commands[j] = ft_strdup(vars.argv[i]);
		i++;
		j++;
	}
	vars.commands[j] = 0;
	return (vars.commands);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	vars;

	if (argc < 5)
	{
		msg("There are less arguments than expected.");
		exit(EXIT_FAILURE);
	}
	vars.f1 = open(argv[1], O_RDONLY);
	vars.f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars.f1 < 0)
		joint_error_msg(argv[1]);
	if (vars.f2 < 0)
	{
		joint_error_msg(argv[4]);
		exit(EXIT_FAILURE);
	}
	vars.paths = parsing_for_path(env);
	vars.argv = argv;
	vars.argc = argc;
	vars.commands = initialize_commands(vars);
	pipex(vars);
	ft_free(vars.paths);
	ft_free(vars.commands);
	return (0);
}
