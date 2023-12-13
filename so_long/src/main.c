/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:42:50 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/13 20:17:03 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	ft_handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		printf("W\n");
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
		printf("A\n");
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		printf("S\n");
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		printf("D\n");
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	ft_check_command_line_arguments(argc, argv);
	ft_init_map(data, argv);
	ft_init_vars(data);
	ft_check_map(data);
	ft_init_mlx(data);
	ft_init_sprites(data);
	ft_render_map(data);
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_handle_keypress, data);
	mlx_hook(data->win, DestroyNotify, ButtonPressMask, ft_close, data);
	mlx_hook(game->win_ptr, Expose, ExposureMask, ft_render_map, game);
	mlx_loop(game->mlx_ptr);
}
