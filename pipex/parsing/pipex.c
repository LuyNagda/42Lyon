/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:19:24 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/08 16:48:27 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	child_one(int f1, char **cmd1, char *path, int end[2])
{
	if (dup2(f1, STDIN_FILENO) == -1)
		return (EXIT_FAILURE);
	if (dup2(end[1], STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	close(end[0]);
	close(f1);
	if (path == NULL)
		return (EXIT_SUCCESS);
	if (execve(path, cmd1, 0) == -1)
		perror(cmd1[0]);
	ft_free(cmd1);
	free(path);
	return (EXIT_FAILURE);
}

int	child_two(int f2, char **cmd2, char *path, int end[2])
{
	int		status;

	waitpid(-1, &status, 0);
	if (dup2(f2, STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	if (dup2(end[0], STDIN_FILENO) == -1)
		return (EXIT_FAILURE);
	close(end[1]);
	close(f2);
	if (path == NULL)
		return (WEXITSTATUS(status));
	if (execve(path, cmd2, 0) == -1)
		perror(cmd2[0]);
	ft_free(cmd2);
	free(path);
	return (EXIT_FAILURE);
}

void	pipex(t_pipex vars)
{
	if (pipe(vars.end) == -1)
		error_msg("pipe");
	vars.child1 = fork();
	if (vars.child1 < 0)
		error_msg("Fork: ");
	if (vars.child1 == 0)
		child_one(vars.f1, vars.cmd1, vars.path1, vars.end);
	vars.child2 = fork();
	if (vars.child2 < 0)
		error_msg("Fork: ");
	if (vars.child2 == 0)
		vars.status = child_two(vars.f2, vars.cmd2, vars.path2, vars.end);
	close(vars.end[0]);
	close(vars.end[1]);
	waitpid(vars.child1, &vars.status, 0);
	waitpid(vars.child2, &vars.status, 0);
	free_stuff(vars.cmd1, vars.cmd2, vars.path1, vars.path2);
	exit(WEXITSTATUS(vars.status));
}
