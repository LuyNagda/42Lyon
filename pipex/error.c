/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:16:20 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/08 16:32:39 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
}

void	error_msg(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
