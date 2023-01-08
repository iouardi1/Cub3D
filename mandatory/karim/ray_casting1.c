/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:04:22 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/08 05:04:35 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_coordinates	last_v_inter(t_data *game_data, \
	t_coordinates last_v_inter, t_angles angles)
{
	double	x_dists;
	double	y_dist;

	x_dists = BLOCK_SIZE;
	if (angles.cos < 0)
		x_dists = (BLOCK_SIZE * -1);
	y_dist = x_dists * -1 * angles.tan;
	while (1)
	{
		if ((angles.cos < 0 && touch_wall(game_data, last_v_inter.x - 1, \
			last_v_inter.y)) || (angles.cos >= 0 && \
				touch_wall(game_data, last_v_inter.x, last_v_inter.y)))
			break ;
		last_v_inter.x += x_dists;
		last_v_inter.y += y_dist;
	}
	return (last_v_inter);
}

t_coordinates	ray_cast(t_data *game_data, double degree)
{
	t_angles		angles;
	t_coordinates	inters[2];

	inters[0] = to_coords(game_data->player.pixel_x, game_data->player.pixel_y);
	inters[1] = to_coords(game_data->player.pixel_x, game_data->player.pixel_y);
	angles = to_angles(degree);
	first_h_inter(&inters[0], angles);
	first_v_inter(&inters[1], angles);
	inters[0] = last_h_inter(game_data, inters[0], angles);
	inters[1] = last_v_inter(game_data, inters[1], angles);
	if (get_distance(game_data, inters[1]) < get_distance(game_data, inters[0]))
		return (inters[1]);
	else
		return (inters[0]);
}
