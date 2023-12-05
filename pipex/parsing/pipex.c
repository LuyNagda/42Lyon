/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:19:24 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/05 16:21:30 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_one(int f1, char **cmd1, char **env, int	end[2])
{
	char	**paths;
	char	*path;

	if (f1 == -1)
		exit(EXIT_FAILURE);
	if (dup2(f1, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (dup2(end[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(end[0]);
	close(f1);
	paths = parsing_for_path(env);
	path = get_path(paths, cmd1);
	if (execve(path, cmd1, paths) == -1)
		perror(cmd1[0]);
	ft_free(cmd1);
	free(path);
	exit(EXIT_SUCCESS);
}

void	child_two(int f2, char **cmd2, char **env, int end[2])
{
	char	**paths;
	char	*path;

	if (f2 == -1)
		exit(EXIT_FAILURE);
	waitpid(-1, NULL, 0);
	if (dup2(f2, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (dup2(end[0], STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(end[1]);
	close(f2);
	paths = parsing_for_path(env);
	path = get_path(paths, cmd2);
	if (execve(path, cmd2, paths) == -1)
		perror(cmd2[0]);
	ft_free(cmd2);
	free(path);
	ft_free(paths);
	exit(EXIT_SUCCESS);
}

void	pipex(int f1, int f2, char **argv, char **env)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(end) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		child_one(f1, ft_split(argv[2], ' '), env, end);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		child_two(f2, ft_split(argv[3], ' '), env, end);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	exit(EXIT_SUCCESS);
}
