/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:38:57 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/15 15:23:26 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_msg(char *msg, t_data *data)
{
	free(data);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

char	*ft_strappend(char	**s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc(((ft_strlen(*s1) + \
	ft_strlen(s2)) + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, (ft_strlen(str) + ft_strlen(s2) + 1));
	free(*s1);
	return (str);
}
