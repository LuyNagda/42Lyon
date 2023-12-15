/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:56:00 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/15 15:13:35 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_walls(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.columns)
		{
			if ((y == 0 || y == data->map.rows - 1) && data->map.full[y][x] != '1')
			{
				ft_free_map(data);
				ft_error_msg("Invalid map. Not covered by walls.\n", data);				
			}
			else if ((x == 0 || x == data->map.columns - 1) && data->map.full[y][x] != '1')
			{
				ft_free_map(data);
				ft_error_msg("Invalid map. Not covered by walls.\n", data);
			}
			x++;
		}
		y++;
	}
}

void	ft_count_map_parameters(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.full[y])
	{
		x = 0;
		while (data->map.full[y][x])
		{
			if (data->map.full[y][x] == 'P')
			{
				data->map.players++;
				data->map.player.x = x;
				data->map.player.y = y;
			}
			if (data->map.full[y][x] == 'E')
				data->map.exit++;
			if (data->map.full[y][x] == 'C')
				data->map.coins++;
			x++;
		}
		y++;
	}
}

void	ft_verify_map_parameters(t_data *data)
{
	if (data->map.coins == 0)
	{
		ft_free_map(data);
		ft_error_msg("Invalid Map. There are no Coins!\n", data);
	}
	else if (data->map.exit == 0)
	{
		ft_free_map(data);
		ft_error_msg("Invalid Map. There is no Exit.\n", data);
	}
	else if (data->map.players != 1)
	{
		ft_free_map(data);
		ft_error_msg("Invalid Map. This is a one player game.\n", data);
	}
}

void	ft_map_is_rectangular(t_data *data)
{
	int		i;
	size_t	len;
	size_t	row_len;
	
	i = 0;
	len = ft_strlen(data->map.full[0]);
	while (i < data->map.rows)
	{
		row_len = ft_strlen(data->map.full[0]);
		if (row_len != len)
		{
			ft_free_map(data);
			ft_error_msg("Invalid map. The map is suppose to be a rectangle.\n", data);
		}
		i++;
	}
}

void	ft_check_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.columns)
		{
			if (!ft_strchr("CEP10", data->map.full[y][x]))
			{
				ft_free_map(data);
				ft_error_msg("Invalid map. Unexpected map parameter.\n", data);							
			}
			x++;
		}
		y++;
	}
	ft_map_is_rectangular(data);
	ft_check_walls(data);
	ft_count_map_parameters(data);
	ft_verify_map_parameters(data);
}
