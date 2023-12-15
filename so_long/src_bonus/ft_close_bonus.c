/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:10:08 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/15 16:06:11 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	ft_destroy_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall.xpm);
	mlx_destroy_image(data->mlx, data->toxic_river.xpm);
	mlx_destroy_image(data->mlx, data->floor.xpm);
	mlx_destroy_image(data->mlx, data->coins.xpm);
	mlx_destroy_image(data->mlx, data->open_exit.xpm);
	mlx_destroy_image(data->mlx, data->closed_exit.xpm);
	mlx_destroy_image(data->mlx, data->player_front.xpm);
	mlx_destroy_image(data->mlx, data->player_back.xpm);
	mlx_destroy_image(data->mlx, data->player_left.xpm);
	mlx_destroy_image(data->mlx, data->player_right.xpm);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.rows)
	{
		free(data->map.full[i]);
		i++;
	}
	free(data->map.full);
}

void	free_all_stuff(t_data *data)
{
	ft_destroy_sprites(data);
	ft_free_map(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}

int	ft_close(t_data *data)
{
	free_all_stuff(data);
	exit(0);
}
