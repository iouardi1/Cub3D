/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:23:53 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/07 23:24:52 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ihsan.h"

void	check_players_angle(t_data *data)
{
	if (data->map.map[data->player.map_y][data->player.map_x] == 'S')
		data->player.angle = (3 * M_PI) / 2;
	if (data->map.map[data->player.map_y][data->player.map_x] == 'N')
		data->player.angle = M_PI_2;
	if (data->map.map[data->player.map_y][data->player.map_x] == 'W')
		data->player.angle = M_PI;
	if (data->map.map[data->player.map_y][data->player.map_x] == 'E')
		data->player.angle = 0;
	data->player.is_down = 0;
	data->player.is_up = 0;
	data->player.is_left = 0;
	data->player.is_right = 0;
	data->player.is_rotate_right = 0;
	data->player.is_rotate_left = 0;
}

int	get_out(t_data *game_data)
{
	free(game_data->vis_settings.cv);
	free(game_data->vis_settings.fv);
	free(game_data);
	exit (0);
}

void	get_players_position_supp1(t_data *data, int i, int j)
{
	data->player.map_x = j;
	data->player.map_y = i;
	data->player.pixel_x = j * BLOCK_SIZE + (BLOCK_SIZE >> 1);
	data->player.pixel_y = i * BLOCK_SIZE + (BLOCK_SIZE >> 1);
}

int	get_players_position_supp2(t_data *data, int i, int j, int p)
{
	if (data->map.map[i][j] != '1' && data->map.map[i][j] != '0' \
		&& data->map.map[i][j] != 'N' && data->map.map[i][j] != 'E' \
			&& data->map.map[i][j] != 'S' && data->map.map[i][j] != 'W' \
				&& data->map.map[i][j] != ' ' && data->map.map[i][j] != '\n')
					return (0);
	if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'W' || \
		data->map.map[i][j] == 'E' || data->map.map[i][j] == 'S')
	{
		get_players_position_supp1(data, i, j);
		check_players_angle(data);
		p++;
	}
	return (p);
}

int	get_players_position(t_data	*data)
{
	int        i;
    int        p;
    int        j;

	i = 0;
	p = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
        {
			p = get_players_position_supp2(data, i, j, p);
			j++;
		}
		i++;
	}
	if (p != 1)
		return (0);
	return (1);
}
