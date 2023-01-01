/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:12:30 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/11/06 20:33:36 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	*get_map(int fd, char *str, t_map *map)
{
	char	*str_map;

	str_map = str;
	map->height = 1;
	map->length = ft_strlen(str_map) - 1;
	str = get_next_line(fd);
	while (str)
	{
		map->height++;
		if (ft_strlen(str) - 1 > (size_t)map->length)
			map->length = ft_strlen(str) - 1;
		str_map = ft_extrajoin(str_map, str, FREE_ALL);
		str = get_next_line(fd);
	}
	return (str_map);
}

void	size_correction(char **old_map, t_map *map)
{
	t_index	i;
	int		hold_length;

	map->map = ft_calloc(map->height + 1, sizeof(char *));
	i = 0;
	while (old_map[i])
	{
		hold_length = ft_strlen(old_map[i]);
		map->map[i] = ft_realloc(old_map[i], hold_length, \
									map->length - hold_length + 1);
		ft_memset(ft_strchr(map->map[i], '\0'), ' ', map->length - hold_length);
		i++;
	}
	free(old_map);
}

void	init_player_data(t_data *data, t_index i, t_index j, int player_count)
{
	data->player.map_y = i;
	data->player.map_x = j;
	data->player.is_down = 0;
	data->player.is_left = 0;
	data->player.is_right = 0;
	data->player.is_up = 0;
	data->player.is_rotate_left = 0;
	data->player.is_rotate_right = 0;
	data->player.pixel_x = (j * BLOCK_SIZE) + (BLOCK_SIZE >> 1);
	data->player.pixel_y = (i * BLOCK_SIZE) + (BLOCK_SIZE >> 1);
	data->player.angle = ((data->map.map[i][j] == 'S') * (3 * M_PI) / 2) + \
							((data->map.map[i][j] == 'W') * M_PI) + \
							((data->map.map[i][j] == 'N') * M_PI_2) + \
							((data->map.map[i][j] == 'E') * 0);
	player_count++;
}

int	check_map_body(t_data *data, t_index i)
{
	t_index	j;
	int		player_count;

	player_count = 0;
	j = 0;
	while (data->map.map[i][j])
	{
		if (ft_strchr("NSEW", data->map.map[i][j]))
			init_player_data(data, i, j, player_count++);
		if (ft_strchr("0NSEW", data->map.map[i][j]))
		{
			if (i == 0 || j == 0 || i == (t_index)data->map.height - 1 || \
									j == (t_index)data->map.length)
				ft_print_error("Error map grid format\n", EXIT_FAILURE);
			else if (data->map.map[i - 1][j] == ' ' || \
						data->map.map[i + 1][j] == ' ' || \
						data->map.map[i][j - 1] == ' ' || \
						data->map.map[i][j + 1] == ' ')
				ft_print_error("Error invalid component positioning\n", \
														EXIT_FAILURE);
		}
		j++;
	}
	return (player_count);
}

void	map_error_checking(t_data *data)
{
	t_index	i;
	int		player_count;

	i = 0;
	player_count = 0;
	while (data->map.map[i])
	{
		if (ft_in_charset(data->map.map[i], " 01NSEW") != MATCH)
			ft_print_error("Error invalid componment in map body\n", \
												EXIT_FAILURE);
		else
			player_count += check_map_body(data, i);
		i++;
	}
	if (player_count != 1)
		ft_print_error("Error wrong player count\n", 2);
}
