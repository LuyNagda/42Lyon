/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:43:08 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/15 14:46:56 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define WINDOW_WIDTH		600
# define WINDOW_HEIGHT		300

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR				'0'
# define COINS				'C'
# define EXIT				'E'
# define PLAYER				'P'

# define WALL_XPM			"assets/wall.xpm"
# define COIN_XPM			"assets/coin-bag.xpm"
# define OPEN_EXIT_XPM		"assets/open-exit.xpm"
# define CLOSED_EXIT_XPM	"assets/exit-closed.xpm"
# define FLOOR_XPM			"assets/floor.xpm"
# define PLAYER_FRONT_XPM	"assets/player/front.xpm"
# define PLAYER_LEFT_XPM	"assets/player/left.xpm"
# define PLAYER_RIGHT_XPM	"assets/player/right.xpm"
# define PLAYER_BACK_XPM	"assets/player/back.xpm"

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			exit;
	int			coins;
	int			players;
	t_position	player;
}	t_map;

typedef struct s_image
{
	void	*xpm;
	int		x;
	int		y;
}	t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			movements;
	int			player_sprite;
	t_image		player_front;
	t_image		player_back;
	t_image		player_left;
	t_image		player_right;
	t_image		coins;
	t_image		wall;
	t_image		floor;
	t_image		open_exit;
	t_image		closed_exit;
	t_map		map;
}	t_data;

void	ft_check_command_line_arguments(int argc, char **argv, t_data *data);
char	*ft_strappend(char	**s1, char *s2);
void	ft_init_map(t_data *data, char **argv);
void	ft_init_vars(t_data *data);
void	ft_check_map(t_data *data);
void	ft_init_mlx(t_data *data);
void	ft_init_sprites(t_data *data);
int		ft_render_map(t_data *data);
int		ft_handle_keypress(int keysym, t_data *data);
int		ft_close(t_data *data);
void	ft_error_msg(char *msg, t_data *data);
void	ft_free(char **s);
void	free_all_stuff(t_data *data);
void	ft_free_map(t_data *data);

#endif