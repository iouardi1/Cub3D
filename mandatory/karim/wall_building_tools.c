/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_building_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:43:30 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/11 15:24:47 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/settings.h"

int	get_texture(t_coordinates x_y_inter, t_angles angles)
{
	if (angles.sin > 0)
	{
		if (x_y_inter.y == 0 && (angles.cos < 0 || angles.cos > 0))
			return (1);
		else if (x_y_inter.y != 0 && angles.cos < 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (x_y_inter.y == 0 && (angles.cos < 0 || angles.cos >= 0))
			return (4);
		else if (x_y_inter.y != 0 && angles.cos < 0)
			return (2);
		else
			return (3);
	}
}

int	get_pixel_color(double x_or_y_inter, t_coordinates coords, double height)
{
	int		res;
	double	y;
	double	row;

	y = coords.y - (((WINDOW_H / 2)) - (height / 2));
	row = (BLOCK_SIZE / height);
	res = (int)(x_or_y_inter) + (((int)(y * row) *BLOCK_SIZE));
	return (res);
}

double	get_wall_start(double height)
{
	double	y;

	y = ((WINDOW_H / 2)) - (height / 2);
	if (y < 0)
		y = 0;
	return (y);
}

double	get_wall_end(double height)
{
	double	y;

	y = ((WINDOW_H / 2)) + (height / 2);
	if (y > WINDOW_H)
		y = WINDOW_H;
	return (y);
}

double	get_wall_height(double dist)
{
	double	height;

	height = (BLOCK_SIZE / dist) * (((WINDOW_W / 2)) / tan(((PI / 3) / 2)));
	return (height);
}
