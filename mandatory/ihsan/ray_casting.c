/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:45:55 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/11/04 03:17:06 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	get_last_h_intersection(t_data *game_data, t_inter *inter)
{
	t_map		*map;

	map = &game_data->map;
	while (inter->dof < DOF)
	{
		if (inter->h_cords.y >= 0 && inter->h_cords.x >= 0 && \
			inter->h_cords.y < BLOCK_SIZE * map->height && \
			inter->h_cords.x < BLOCK_SIZE * map->length && \
			map->map[((long)(inter->h_cords.y - (inter->angles_data.sin >= 0)) \
				/ BLOCK_SIZE)][(long)(inter->h_cords.x) / BLOCK_SIZE] == '1')
		{
			inter->dof = DOF;
			break ;
		}
		inter->h_cords.x += inter->h_x_jump;
		inter->h_cords.y += inter->h_y_jump;
		inter->dof++;
	}
}

void	get_first_h_intersection(t_data *game_data, t_inter *inter)
{
	inter->dof = 0;
	inter->h_cords.y = (floor(game_data->player.pixel_y / BLOCK_SIZE) \
														* BLOCK_SIZE);
	inter->h_y_jump = -BLOCK_SIZE;
	if (inter->angles_data.sin < 0)
	{
		inter->h_cords.y += BLOCK_SIZE;
		inter->h_y_jump = BLOCK_SIZE;
	}
	inter->h_cords.x = (game_data->player.pixel_y - inter->h_cords.y) / \
						inter->angles_data.tan + game_data->player.pixel_x;
	inter->h_x_jump = -inter->h_y_jump / inter->angles_data.tan;
	if (inter->angles_data.sin == 0)
		inter->dof = DOF;
	get_last_h_intersection(game_data, inter);
}

void	get_last_v_intersection(t_data *game_data, t_inter *inter)
{
	t_map		*map;

	map = &game_data->map;
	while (inter->dof < DOF)
	{
		if (inter->v_cords.y >= 0 && inter->v_cords.x >= 0 && \
			inter->v_cords.y < BLOCK_SIZE * map->height && \
			inter->v_cords.x < BLOCK_SIZE * map->length && \
			map->map[(long)(inter->v_cords.y) / BLOCK_SIZE] \
			[((long)(inter->v_cords.x - \
			(inter->angles_data.cos <= 0)) / BLOCK_SIZE)] == '1')
		{
			inter->dof = DOF;
			break ;
		}
		inter->v_cords.x += inter->v_x_jump;
		inter->v_cords.y += inter->v_y_jump;
		inter->dof++;
	}
}

void	get_first_v_intersection(t_data *game_data, t_inter *inter)
{
	inter->dof = 0;
	inter->v_cords.x = (floor(game_data->player.pixel_x / BLOCK_SIZE) \
														* BLOCK_SIZE);
	inter->v_x_jump = -BLOCK_SIZE;
	if (inter->angles_data.cos > 0)
	{
		inter->v_cords.x += BLOCK_SIZE;
		inter->v_x_jump = BLOCK_SIZE;
	}
	inter->v_cords.y = (game_data->player.pixel_x - inter->v_cords.x) * \
						inter->angles_data.tan + game_data->player.pixel_y;
	inter->v_y_jump = -inter->v_x_jump * inter->angles_data.tan;
	if (inter->angles_data.cos == 0)
		inter->dof = DOF;
	get_last_v_intersection(game_data, inter);
}

t_coordinates	get_wall_intersection(t_data *game_data, double angle)
{
	t_inter			*inter;
	t_coordinates	cords;

	inter = ft_calloc(sizeof(t_inter), 1);
	inter->angles_data = to_angles(angle);
	get_first_h_intersection(game_data, inter);
	get_first_v_intersection(game_data, inter);
	get_short_dist(&game_data->player, inter, &cords, angle);
	free(inter);
	return (cords);
}
