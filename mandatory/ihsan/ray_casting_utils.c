/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:17:11 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/11/04 03:17:25 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	get_short_dist(t_player *player, t_inter *inter, \
						t_coordinates *cords, double angle)
{
	double	v_d;
	double	h_d;

	if (inter->angles_data.cos > 0.0)
		h_d = fabs(inter->h_cords.x - player->pixel_x) / inter->angles_data.cos;
	else
		h_d = fabs(inter->h_cords.y - player->pixel_y) / \
				fabs(inter->angles_data.sin);
	if (inter->angles_data.sin > 0.0)
		v_d = fabs(inter->v_cords.y - player->pixel_y) / inter->angles_data.sin;
	else
		v_d = fabs(inter->v_cords.x - player->pixel_x) / \
				fabs(inter->angles_data.cos);
	if (v_d < h_d)
	{
		cords->x = inter->v_cords.x;
		cords->y = inter->v_cords.y;
		cords->correct_dist = v_d * cos(player->angle - angle);
	}
	else
	{
		cords->x = inter->h_cords.x;
		cords->y = inter->h_cords.y;
		cords->correct_dist = h_d * cos(player->angle - angle);
	}
}
