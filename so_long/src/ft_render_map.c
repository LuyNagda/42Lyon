/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:55:24 by luynagda          #+#    #+#             */
/*   Updated: 2023/12/15 15:23:13 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_sprite(t_data *data, t_image sprite, int line, int column)
{
	mlx_put_image_to_window(data->mlx, data->win, \
	sprite.xpm, column * sprite.x, line * sprite.y);
}

void	ft_render_player(t_data *data, int y, int x)
{
	if (data->player_sprite == FRONT)
		ft_render_sprite(data, data->player_front, y, x);
	if (data->player_sprite == BACK)
		ft_render_sprite(data, data->player_back, y, x);
	if (data->player_sprite == RIGHT)
		ft_render_sprite(data, data->player_right, y, x);
	if (data->player_sprite == LEFT)
		ft_render_sprite(data, data->player_left, y, x);
}

void	ft_print_movements(t_data *data)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(data->movements);
	phrase = ft_strjoin("Movements: ", movements);
	mlx_string_put(data->mlx, data->win, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}

void	ft_identify_sprite(t_data *data, int y, int x)
{
	char	parameter;

	parameter = data->map.full[y][x];
	if (parameter == WALL)
		ft_render_sprite(data, data->wall, y, x);
	else if (parameter == FLOOR)
		ft_render_sprite(data, data->floor, y, x);
	else if (parameter == COINS)
		ft_render_sprite(data, data->coins, y, x);
	else if (parameter == EXIT)
	{
		if (data->map.coins == 0)
			ft_render_sprite(data, data->open_exit, y, x);
		else
			ft_render_sprite(data, data->closed_exit, y, x);
	}
	else if (parameter == PLAYER)
		ft_render_player(data, y, x);
}

int	ft_render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.columns)
		{
			ft_identify_sprite(data, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(data);
	return (0);
}
