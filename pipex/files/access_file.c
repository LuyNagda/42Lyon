/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:19:11 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/04 16:29:59 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	access_input_file(char *file1)
{
	if (access(file1, F_OK) == 0 && access(file1, R_OK) == 0)
		return (1);
	perror(file1);
	return (0);
}

int	access_output_file(char *file2)
{
	if (access(file2, F_OK) == 0 && access(file2, W_OK) == 0)
		return (1);
	perror(file2);
	return (0);
}
