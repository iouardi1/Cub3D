/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:58:31 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/08 05:04:21 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	touch_wall(t_data *game_data, int pixel_x, int pixel_y)
{
	int		block_x;
	int		block_y;

	block_x = pixel_x / BLOCK_SIZE;
	block_y = pixel_y / BLOCK_SIZE;
	if (pixel_x < 0 || pixel_y < 0 || block_x > (int)game_data->map.length - 1 \
		|| block_y > (int)game_data->map.height - 1)
		return (1);
	if (game_data->map.map[pixel_y / BLOCK_SIZE][pixel_x / BLOCK_SIZE] == '1')
		return (1);
	return (0);
}

double	get_distance(t_data *game_data, t_coordinates coords)
{
	double	dx;
	double	dy;
	double	distance;

	dx = fabs(game_data->player.pixel_x - coords.x);
	dy = fabs(game_data->player.pixel_y - coords.y);
	distance = sqrtf(pow(dx, 2) + pow(dy, 2));
	return (distance);
}

void	first_h_inter(t_coordinates *player, t_angles angles)
{
	t_coordinates	inter;

	if (angles.sin >= 0)
		inter.y = ((floor(player->y / BLOCK_SIZE)) * BLOCK_SIZE);
	else
		inter.y = ((floor(player->y / BLOCK_SIZE)) * BLOCK_SIZE) + BLOCK_SIZE;
	inter.x = player->x + ((player->y - inter.y) / angles.tan);
	*player = inter;
}

void	first_v_inter(t_coordinates *player, t_angles angles)
{
	t_coordinates	inter;

	if (angles.cos <= 0)
		inter.x = ((floor(player->x / BLOCK_SIZE)) * BLOCK_SIZE);
	else
		inter.x = (floor(player->x / BLOCK_SIZE)) * BLOCK_SIZE + BLOCK_SIZE;
	inter.y = player->y + ((player->x - inter.x) * angles.tan);
	*player = inter;
}

t_coordinates	last_h_inter(t_data *game_data, \
	t_coordinates last_h_inter, t_angles angles)
{
	double	x_dists;
	double	y_dist;

	y_dist = BLOCK_SIZE;
	if (angles.sin > 0)
		y_dist = (BLOCK_SIZE * -1);
	x_dists = (y_dist * -1) / angles.tan;
	while (1)
	{
		if ((angles.sin > 0 && touch_wall(game_data, last_h_inter.x, \
			last_h_inter.y - 1)) || (angles.sin <= 0 && \
				touch_wall(game_data, last_h_inter.x, last_h_inter.y)))
			break ;
		last_h_inter.x += x_dists;
		last_h_inter.y += y_dist;
	}
	return (last_h_inter);
}
