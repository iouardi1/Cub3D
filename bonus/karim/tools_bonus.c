/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:36:51 by achedmi           #+#    #+#             */
/*   Updated: 2022/11/06 22:24:02 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/settings_bonus.h"

void	index_to_img(t_data	*game_data, int i, \
int *width, int *height)
{
	if (i == 1)
		game_data->mlx_settings.imgs[i].img = \
		mlx_xpm_file_to_image(game_data->mlx_settings.mlx, \
		game_data->vis_settings.no, width, height);
	else if (i == 2)
		game_data->mlx_settings.imgs[i].img = \
		mlx_xpm_file_to_image(game_data->mlx_settings.mlx, \
		game_data->vis_settings.ea, width, height);
	else if (i == 3)
		game_data->mlx_settings.imgs[i].img = \
		mlx_xpm_file_to_image(game_data->mlx_settings.mlx, \
		game_data->vis_settings.we, width, height);
	else if (i == 4)
		game_data->mlx_settings.imgs[i].img = \
		mlx_xpm_file_to_image(game_data->mlx_settings.mlx, \
		game_data->vis_settings.so, width, height);
}

t_coordinates	to_coords(double x, double y)
{
	t_coordinates	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}

t_angles	to_angles(double deg)
{
	t_angles	angles;

	angles.angle = deg;
	angles.cos = cos(deg);
	angles.sin = sin(deg);
	angles.tan = tan(deg);
	return (angles);
}
