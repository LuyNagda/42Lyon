/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:35:30 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/08 16:32:25 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h> 
# include <stdio.h>
# include <sys/wait.h>

typedef struct	s_pipex
{
	int 	f1;
	int		f2;
	char	**paths;
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
	int		end[2];
	int		status;
	int		child1;
	int		child2;
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
void	error_msg(char *err);
void	free_stuff(char **cmd1, char **cmd2, char *path1, char *path2);

#endif