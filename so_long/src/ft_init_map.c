/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:37:09 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/15 15:21:38 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_command_line_arguments(int argc, char **argv, t_data *data)
{
	if (argc > 2)
		ft_error_msg("Too many arguments. \
		Just send a path to the map.\n", data);
	if (argc < 2)
		ft_error_msg("Too less arguments. Send a path to the map.\n", data);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_error_msg("The map is supposed to have .ber extension.\n", data);
}

void	ft_check_for_empty_lines(char *map, t_data *data)
{
	int	i;

	i = 0;
	if (map[0] == '\n' || map[0] == '\r')
	{
		free(map);
		ft_error_msg("Invalid map. Map has a empty line in the start.\n", data);
	}
	if (map[ft_strlen(map) - 1] == '\n' || map[ft_strlen(map) - 1] == '\r')
	{
		free(map);
		ft_error_msg("Invalid map. Map has a empty line in the end.\n", data);
	}
	while (map[i + 2])
	{
		if ((map[i] == '\n' || map[i] == '\r') && \
		(map[i + 2] == '\n' || map[i + 2] == '\r'))
		{
			free(map);
			ft_error_msg("Invalid map. \
			Map has a empty line in the middle.\n", data);
		}
		i++;
	}
}

void	ft_init_map(t_data *data, char **argv)
{
	int		map_fd;
	char	*line_temp;
	char	*map_temp;

	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The map couldn't be opened. Does it exist?\n", data);
	map_temp = strdup("");
	data->map.rows = 0;
	while (1)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		data->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_lines(map_temp, data);
	data->map.full = ft_split(map_temp, '\n');
	free(map_temp);
}
