/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:16:20 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/11 16:58:06 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
}

void	error_msg(char *err, t_pipex vars)
{
	free_stuff(vars.commands, vars.command, vars.paths, vars.path);
	perror(err);
	exit(EXIT_FAILURE);
}

void	joint_error_msg(char *err)
{
	char	*err_msg;

	err_msg = ft_strjoin(strerror(errno), ": ");
	err_msg = ft_strjoin_free(err_msg, err);
	msg(err_msg);
	free(err_msg);
}
