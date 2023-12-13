/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:18:02 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/13 16:28:07 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strcchr(const char *s, int c);
char	*ft_strcatdup(char *dst, const char *src);
char	*ft_strnddup(char *src, int start, int stop);
size_t	ft_strllen(const char *s);
char	*ft_strddup(const char *src);

#endif
