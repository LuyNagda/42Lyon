/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:43:08 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/13 16:34:05 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define RIGHT 3
# define LEFT 2
# define UP 1
# define DOWN 4

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			movements;
	int			player_sprite;
	t_image		img;
	t_map		map;
}	t_data;

void	ft_check_command_line_arguments(int argc, char **argv);
char	*ft_strappend(char	**s1, char *s2);
void	ft_init_map(t_data *data, char **argv);
void	ft_init_vars(t_data *data);
void	ft_check_map(t_data *data);

void	ft_error_msg_free_map(char *msg, char *map);
void	ft_error_msg(char *msg);

#endif