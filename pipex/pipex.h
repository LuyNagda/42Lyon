/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:35:30 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/11 16:59:06 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "utils/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h> 
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		f1;
	int		f2;
	int		argc;
	char	**argv;
	char	**paths;
	char	*path;
	char	**commands;
	char	**command;
	int		pipe[2];
	int		old_pipe[2];
	int		status;
	int		child;
	int		i;
}	t_pipex;

char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
void	ft_free(char **args);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**parsing_for_path(char **env);
char	*get_path(char **paths, char **cmd);
int		access_input_file(char *file1);
int		access_output_file(char *file2);
void	pipex(t_pipex vars);
void	msg(char *err);
void	error_msg(char *err, t_pipex vars);
void	free_stuff(char **commands, char **command, char **paths, char *path);
char	*ft_strjoin_free(char const *s1, char const *s2);
void	joint_error_msg(char *err);
void	free_command_path(char **command, char *path);
int		ft_strcmp(const char *s1, const char *s2);

#endif