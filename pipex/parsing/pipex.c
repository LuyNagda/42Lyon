/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:19:24 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/16 13:35:46 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_child(t_pipex vars, int pipe[2])
{
	if (dup2(vars.f1, STDIN_FILENO) == -1)
		error_msg("Dup", vars);
	if (dup2(pipe[1], STDOUT_FILENO) == -1)
		error_msg("Dup", vars);
	close(pipe[0]);
	close(vars.f1);
	if (vars.path == NULL)
		exit(EXIT_FAILURE);
	if (execve(vars.path, vars.command, 0) == -1)
		joint_error_msg(vars.command[0]);
	exit(EXIT_FAILURE);
}

void	child_n(t_pipex vars, int pipe[2], int old_pipe[2])
{
	if (dup2(old_pipe[0], STDIN_FILENO) == -1)
		error_msg("Dup", vars);
	if (dup2(pipe[1], STDOUT_FILENO) == -1)
		error_msg("Dup", vars);
	close(old_pipe[0]);
	close(pipe[0]);
	close(pipe[1]);
	if (vars.path == NULL)
		exit(EXIT_FAILURE);
	if (execve(vars.path, vars.command, 0) == -1)
		joint_error_msg(vars.command[0]);
	exit(EXIT_FAILURE);
}

int	last_child(t_pipex vars, int old_pipe[2], int pipe[2])
{
	if (dup2(old_pipe[0], STDIN_FILENO) == -1)
		error_msg("Dup", vars);
	if (dup2(vars.f2, STDOUT_FILENO) == -1)
		error_msg("Dup", vars);
	close(old_pipe[0]);
	close(pipe[0]);
	close(pipe[1]);
	close(vars.f2);
	if (vars.path == NULL)
	{
		free_stuff(vars.commands, vars.command, vars.paths, vars.path);
		exit(EXIT_FAILURE);
	}
	if (execve(vars.path, vars.command, 0) == -1)
		joint_error_msg(vars.command[0]);
	free_stuff(vars.commands, vars.command, vars.paths, vars.path);
	exit(EXIT_FAILURE);
}

void	pipex(t_pipex vars)
{
	int		i;
	int		old_pipe[2];

	i = 0;
	while (vars.commands[i])
	{
		if (pipe(vars.pipe) == -1)
			error_msg("Pipe", vars);
		vars.command = ft_split(vars.commands[i], ' ');
		vars.path = get_path(vars.paths, vars.command);
		vars.child = fork();
		if (vars.child < 0)
			error_msg("Fork", vars);
		if (i == 0 && vars.child == 0)
			first_child(vars, vars.pipe);
		else if (i < (vars.argc - 4) && vars.child == 0)
			child_n(vars, vars.pipe, old_pipe);
		else if (i == (vars.argc - 4) && vars.child == 0)
			last_child(vars, old_pipe, vars.pipe);
		close(vars.pipe[1]);
		old_pipe[0] = vars.pipe[0];
		i++;
		free_command_path(vars.command, vars.path);
	}
}
