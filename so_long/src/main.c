/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:42:50 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/12 16:53:57 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
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

int	handle_mousepress(int mousesym, t_data *data)
{
	if (mousesym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Mousepress: %d\n", mousesym);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	/* Setup hooks */ 
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_keypress, &data);
	mlx_mouse_hook(data.win_ptr, &handle_mousepress, &data);

	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
