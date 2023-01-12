/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:32:52 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/10 05:03:57 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/settings.h"

void	draw_sky(t_data	*game_data, t_coordinates coords)
{
	int	y;
	int	color;

	y = 0;
	color = (0 << 24) | (game_data->vis_settings.cv[0] << 16) | \
	(game_data->vis_settings.cv[1] << 8) | game_data->vis_settings.cv[2];
	while (y < coords.y)
	{
		my_mlx_pixel_put(&game_data->mlx_settings, \
		to_coords(coords.x, y), color);
		y ++;
	}
}

void	draw_floor(t_data	*game_data, t_coordinates coords)
{
	int	color;

	color = (0 << 24) | (game_data->vis_settings.fv[0] << 16) | \
	(game_data->vis_settings.fv[1] << 8) | game_data->vis_settings.fv[2];
	while (coords.y < WINDOW_H)
	{
		my_mlx_pixel_put(&game_data->mlx_settings, coords, color);
		coords.y++;
	}
}
