/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:18:02 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/03 11:18:02 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../push_swap.h"

int		get_next_line(int fd, char **line);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_strcatdup(char *dst, const char *src);
char	*ft_strndup(char *src, int start, int stop);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);

#endif
