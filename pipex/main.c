/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:50:33 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/16 13:18:52 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	initialize_vars(t_pipex vars, int argc, char **argv, char **env)
{
	int	i;
	int	j;

	vars.paths = parsing_for_path(env);
	vars.argv = argv;
	vars.argc = argc;
	i = 2;
	j = 0;
	if (ft_strcmp(argv[1], "here_doc") == 0)
		i = 3;
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
	if (ft_strcmp(argv[1], "here_doc") == 0)
		vars.argc--;
	return (vars);
}

t_pipex	file_handling(t_pipex vars, char **argv, int argc, char **env)
{
	vars.f1 = open(argv[1], O_RDONLY);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		vars.f2 = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		vars.f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars.f1 < 0)
		joint_error_msg(argv[1]);
	if (vars.f2 < 0)
	{
		joint_error_msg(argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
	vars = initialize_vars(vars, argc, argv, env);
	pipex(vars);
	ft_free(vars.paths);
	ft_free(vars.commands);
	exit (EXIT_SUCCESS);
}

t_pipex	here_doc(char **argv, t_pipex vars)
{
	char	*line;

	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		vars.f1 = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (vars.f1 < 0)
			joint_error_msg(argv[1]);
		while (get_next_line(0, &line) && strcmp(line, argv[2]) != 0)
		{
			line = ft_strjoin_free(line, "\n");
			write(vars.f1, line, ft_strlen(line));
			free(line);
		}
		free(line);
		close(vars.f1);
	}
	return (vars);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	vars;

	if (argc < 5)
	{
		msg("There are less arguments than expected.");
		exit(EXIT_FAILURE);
	}
	vars = here_doc(argv, vars);
	file_handling(vars, argv, argc, env);
	return (0);
}
