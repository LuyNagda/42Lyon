/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:15:06 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/08 16:46:35 by lunagda          ###   ########.fr       */
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


void	free_stuff(char **cmd1, char **cmd2, char *path1, char *path2)
{
	if (cmd1)
		ft_free(cmd1);
	if (cmd2)
		ft_free(cmd2);
	if (path1)
		free(path1);
	if (path2)
		free(path2);
}
