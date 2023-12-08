/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:38:19 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/08 16:44:47 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*trg;
	int		i;
	int		s1_len;
	int		s2_len;

	i = 0;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	trg = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!trg)
		return (free((char *)s1), NULL);
	while (s1[i])
	{
		trg[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		trg[s1_len++] = s2[i++];
	trg[s1_len] = '\0';
	return (free((char *)s1), trg);
}

char	*get_path(char **paths, char **cmd)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	if (access(cmd[0], F_OK) == 0 && access(cmd[0], X_OK) == 0)
		return (ft_strdup(cmd[0]));
	while (paths[i])
	{
		paths[i] = ft_strjoin_free(paths[i], "/");
		path = ft_strjoin(paths[i], cmd[0]);
		if (access(path, F_OK) == 0
			&& access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	path = ft_strjoin("command not found: ", cmd[0]);
	msg(path);
	return (free(path), NULL);
}
