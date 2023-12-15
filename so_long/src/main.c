/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:42:50 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/15 14:51:21 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	ft_check_command_line_arguments(argc, argv, data);
	ft_init_map(data, argv);
	ft_init_vars(data);
	ft_check_map(data);
	ft_init_mlx(data);
	ft_init_sprites(data);
	ft_render_map(data);
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_handle_keypress, data);
	mlx_hook(data->win, DestroyNotify, ButtonPressMask, ft_close, data);
	mlx_hook(data->win, Expose, ExposureMask, ft_render_map, data);
	mlx_loop(data->mlx);
	return (0);
}
