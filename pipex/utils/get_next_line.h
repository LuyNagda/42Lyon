/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:18:02 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/11 13:47:12 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../pipex.h"

int		get_next_line(int fd, char **line);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_strcatdup(char *dst, const char *src);
char	*ft_strnddup(char *src, int start, int stop);
char	*ft_strddup(const char *src);

#endif
