/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:15:06 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/09 16:08:28 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}


void	free_stuff(char **commands, char **command,
		char **paths, char *path)
{
	if (commands)
		ft_free(commands);
	if (command)
		ft_free(command);
	if (paths)
		ft_free(paths);
	if (path)
		free(path);
}

void	free_command_path(char **command, char *path)
{
	if (command)
		ft_free(command);
	if (path)
		free(path);
}