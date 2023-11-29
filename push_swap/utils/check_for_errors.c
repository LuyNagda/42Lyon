/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:09:40 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/29 15:57:28 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
	{
		if (num[1] == '\0')
			return (-1);
		i++;
	}
	while (num[i])
	{
		if (!ft_strchr("0123456789", num[i]))
			return (-1);
		i++;
	}
	return (0);
}

char	**initialize_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	return (args);
}

int	check_for_duplicates(int argc, char **argv)
{
	char	**args;
	int		i;
	int		j;

	i = 0;
	if (argc != 2)
		i = 1;
	args = initialize_args(argc, argv);
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_strcmp(args[i], args[j]) == 0)
			{
				ft_free(argc, args);
				write(2, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	ft_free(argc, args);
	return (0);
}

int	check_for_errors(int argc, char **argv)
{
	int			i;
	long int	temp;
	char		**args;

	i = 0;
	if (argc != 2)
		i = 1;
	args = initialize_args(argc, argv);
	while (args[i])
	{
		temp = ft_strict_atoi(args[i]);
		if (ft_isnum(args[i]) == -1 || temp < -2147483648 || temp > 2147483647)
		{
			ft_free(argc, args);
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	ft_free(argc, args);
	return (0);
}
