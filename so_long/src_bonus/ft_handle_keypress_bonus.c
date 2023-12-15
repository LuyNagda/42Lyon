/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keypress_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:37:04 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/15 16:35:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	ft_victory(t_data *data)
{
	ft_putstr_fd("\n			Movements: ", 1);
	ft_putnbr_fd(++data->movements, 1);
	ft_putchar_fd('\n', 1);
	free_all_stuff(data);
	ft_putstr_fd("\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
", 1);
	exit(EXIT_SUCCESS);
}

void	ft_loss(t_data *data)
{
	ft_putstr_fd("\n			Movements: ", 1);
	ft_putnbr_fd(++data->movements, 1);
	ft_putchar_fd('\n', 1);
	free_all_stuff(data);
	ft_putstr_fd("\n\
█████████████████████████████████████████████████████████████████████\n\
██                                                                 ██\n\
██  ███  ███  ██████  ██    ██     ██      ██████   ██████ ██████  ██\n\
██   ██  ██  ██    ██ ██    ██     ██     ██    ██ ██      ██      ██\n\
██    ████   █      █ ██    ██     ██     █      █   ████  █████   ██\n\
██     ██    ██    ██ ██    ██     ██     ██    ██      ██ ██      ██\n\
██     ██     ██████    ████       ██████  ██████  ██████  ██████  ██\n\
██                                                                 ██\n\
█████████████████████████████████████████████████████████████████████\n\n\
", 2);
	exit(EXIT_FAILURE);
}

void	ft_player_move(t_data *data, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	data->player_sprite = player_sprite;
	last_x = data->map.player.x;
	last_y = data->map.player.y;
	if (data->map.full[new_y][new_x] == EXIT && data->map.coins == 0)
		ft_victory(data);
	if (data->map.full[new_y][new_x] == TOXIC_RIVER)
		ft_loss(data);
	if (data->map.full[new_y][new_x] == FLOOR || \
	data->map.full[new_y][new_x] == COINS)
	{
		data->map.full[last_y][last_x] = FLOOR;
		if (data->map.full[new_y][new_x] == COINS)
			data->map.coins--;
		data->map.player.x = new_x;
		data->map.player.y = new_y;
		data->map.full[new_y][new_x] = PLAYER;
		data->movements++;
		ft_render_map(data);
	}
}

int	ft_handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_close(data);
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		ft_player_move(data, data->map.player.y - 1, data->map.player.x, BACK);
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
		ft_player_move(data, data->map.player.y, data->map.player.x - 1, LEFT);
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		ft_player_move(data, data->map.player.y + 1, data->map.player.x, FRONT);
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		ft_player_move(data, data->map.player.y, data->map.player.x + 1, RIGHT);
	return (0);
}
