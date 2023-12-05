/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piped_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:55:25 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/04 17:02:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_piped_commands(char *cmd1, char *cmd2)
{
	char	**shell_command;

	shell_command = (char **)malloc(4 * sizeof(char *));
	shell_command[0] = ft_strdup("/bin/sh");
	shell_command[1] = ft_strdup("-c");
	shell_command[2] = ft_strjoin(ft_strjoin(cmd1, " | "), cmd2);
	shell_command[3] = 0;
	return (shell_command);
}
