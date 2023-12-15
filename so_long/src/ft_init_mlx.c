/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:28:27 by luynagda          #+#    #+#             */
/*   Updated: 2023/12/15 15:42:11 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_vars(t_data *data)
{
	data->map.coins = 0;
	data->map.players = 0;
	data->map.exit = 0;
	data->movements = 0;
	data->map.columns = ft_strlen(data->map.full[0]) - 1;
	data->player_sprite = RIGHT;
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_error_msg("Couldn't allocate mlx pointer.\n", data);
	data->win = mlx_new_window(data->mlx, data->map.columns * IMG_WIDTH, \
	data->map.rows * IMG_HEIGHT, "so_long");
	if (data->win == NULL)
	{
		free(data->mlx);
		ft_error_msg("Couldn't create the window.\n", data);
	}
}

t_image	ft_new_sprite(void *mlx, char *path, t_data *data)
{
	t_image	sprite;

	sprite.xpm = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm == NULL)
		ft_error_msg("Couldn't find a sprite.", data);
	return (sprite);
}

void	ft_init_sprites(t_data *data)
{
	void	*mlx;

	mlx = data->mlx;
	data->wall = ft_new_sprite(mlx, WALL_XPM, data);
	data->floor = ft_new_sprite(mlx, FLOOR_XPM, data);
	data->coins = ft_new_sprite(mlx, COIN_XPM, data);
	data->player_front = ft_new_sprite(mlx, PLAYER_FRONT_XPM, data);
	data->player_back = ft_new_sprite(mlx, PLAYER_BACK_XPM, data);
	data->player_right = ft_new_sprite(mlx, PLAYER_RIGHT_XPM, data);
	data->player_left = ft_new_sprite(mlx, PLAYER_LEFT_XPM, data);
	data->open_exit = ft_new_sprite(mlx, OPEN_EXIT_XPM, data);
	data->closed_exit = ft_new_sprite(mlx, CLOSED_EXIT_XPM, data);
}
