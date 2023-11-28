/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:09:40 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/28 20:24:37 by luynagda         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_for_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		if (ft_strict_atoi(argv[i]) > 2147483647
			|| ft_strict_atoi(argv[i]) < -2147483648)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
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
		if (argv[argc][0] == '\0' || argv[argc][i] == '\0')
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
