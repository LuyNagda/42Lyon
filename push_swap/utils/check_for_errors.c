/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:09:40 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/27 13:01:41 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == '\0' && c != '\0' && c != 1024)
		return (0);
	return (1);
}

int	check_for_errors(int argc, char **argv)
{
	int	i;

	argc--;
	while (argc)
	{
		i = 0;
		if (argv[argc][0] == '-')
			i = 1;
		if (argv[argc][0] == '\0')
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		while (argv[argc][i])
		{
			if (!ft_strchr("0123456789", argv[argc][i]))
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			i++;
		}
		argc--;
	}
	return (0);
}
