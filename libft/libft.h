/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:47:35 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/07 11:13:26 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>

int				ft_atoi(char *str);
void			*ft_bzero(void *dst, int n);
void			*calloc(unsigned int nitems, unsigned int size);
int				ft_isalnum(int argument);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int arg);
int				ft_isprint(int c);
void			*ft_memchr(void *str, int c, unsigned int n);
int				ft_memcmp(void *str1, void *str2, unsigned int n);
void			*ft_memcpy(void *dest, void *src, int n);
void			*ft_memmove(void *dest, void *src, unsigned int n);
void			*ft_memset(void *s, int c, int n);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(char *src);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strlcpy(char *dest, char *src, unsigned int len);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strnstr(char *big, char *little, unsigned int len);
char			*ft_strrchr(char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif