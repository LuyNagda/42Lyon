/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:38:19 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/08 13:16:43 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_path(char **paths, char **cmd)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	if (access(cmd[0], F_OK) == 0 && access(cmd[0], X_OK) == 0)
	{
		ft_free(paths);
		return (cmd[0]);
	}
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		path = ft_strjoin(paths[i], cmd[0]);
		if (access(ft_strjoin(paths[i], cmd[0]), F_OK) == 0
			&& access(ft_strjoin(paths[i], cmd[0]), X_OK) == 0)
			return (ft_strjoin(paths[i], cmd[0]));
		free(path);
		i++;
	}
	path = ft_strjoin("command not found: ", cmd[0]);
	msg(path);
	return (ft_free(paths), free(path), NULL);
}
