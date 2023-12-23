/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:14:00 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/23 13:17:40 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	is_solvable(t_data *data, int x, int y)
{
	char	parameter;

	if (y > data->map.rows || x > data->map.columns || x < 0 || y < 0)
		return ;
	parameter = data->map.full[y][x];
	if (parameter == 'O')
		return ;
	if (parameter == '0' || parameter == 'C'
		|| parameter == 'P' || parameter == 'E')
	{
		if (parameter == 'E')
		{
			data->map.full[y][x] = 'L';
			return ;
		}
		else
			data->map.full[y][x] = 'O';
		is_solvable(data, x - 1, y);
		is_solvable(data, x + 1, y);
		is_solvable(data, x, y + 1);
		is_solvable(data, x, y - 1);
	}
	return ;
}

void	find_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.columns)
		{
			if (data->map.full[y][x] == 'P')
			{
				data->map.player.x = x;
				data->map.player.y = y;
			}
			x++;
		}
		y++;
	}
	is_solvable(data, data->map.player.x, data->map.player.y);
}

int	ft_map_solver(t_data *data, char **argv)
{
	ft_init_map(data, argv);
	ft_init_vars(data);
	find_player(data);
	ft_count_map_parameters(data);
	ft_free_map(data);
	if (data->map.coins > 0 || data->map.exit > 0)
	{
		ft_error_msg("Invalid Map. Map is not solvable.\n", data);
	}
	return (0);
}
