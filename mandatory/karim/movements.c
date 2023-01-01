/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:22:23 by achedmi           #+#    #+#             */
/*   Updated: 2022/11/06 21:21:48 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/settings.h"

int	should_move(t_data	*game_data, int x, int y)
{
	if (game_data->map.map[(int)(y / BLOCK_SIZE)][(int)(x / BLOCK_SIZE)] == '1')
		return (0);
	return (1);
}

void	move_up(t_data	*game_data)
{
	int			step;
	t_angles	angles;

	step = STEP_SIZE;
	angles = to_angles(game_data->player.angle);
	if (should_move(game_data, game_data->player.pixel_x + \
	((step * 2) * angles.cos), game_data->player.pixel_y))
		game_data->player.pixel_x += step * cos(game_data->player.angle);
	if (should_move(game_data, game_data->player.pixel_x, \
	game_data->player.pixel_y - ((step * 2) * angles.sin)))
		game_data->player.pixel_y -= step * sin(game_data->player.angle);
}

void	move_down(t_data	*game_data)
{
	int			step;
	t_angles	angles;

	step = STEP_SIZE;
	angles = to_angles(game_data->player.angle - (M_PI));
	if (should_move(game_data, game_data->player.pixel_x + \
	((step * 2) * angles.cos), game_data->player.pixel_y))
		game_data->player.pixel_x -= step * cos(game_data->player.angle);
	if (should_move(game_data, game_data->player.pixel_x, \
	game_data->player.pixel_y - ((step * 2) * angles.sin)))
		game_data->player.pixel_y += step * sin(game_data->player.angle);
}

void	move_right(t_data	*game_data)
{
	int			step;
	t_angles	angles;

	step = STEP_SIZE;
	angles = to_angles(game_data->player.angle - M_PI_2);
	if (should_move(game_data, game_data->player.pixel_x + \
	((step * 2) * angles.cos), game_data->player.pixel_y))
		game_data->player.pixel_x += step * sin(game_data->player.angle);
	if (should_move(game_data, game_data->player.pixel_x, \
	game_data->player.pixel_y - ((step * 2) * angles.sin)))
		game_data->player.pixel_y += step * cos(game_data->player.angle);
}

void	move_left(t_data *game_data)
{
	int			step;
	t_angles	angles;

	step = STEP_SIZE;
	angles = to_angles(game_data->player.angle + M_PI_2);
	if (should_move(game_data, game_data->player.pixel_x + \
	((step * 2) * angles.cos), game_data->player.pixel_y))
		game_data->player.pixel_x -= step * sin(game_data->player.angle);
	if (should_move(game_data, game_data->player.pixel_x, \
	game_data->player.pixel_y - ((step * 2) * angles.sin)))
		game_data->player.pixel_y -= step * cos(game_data->player.angle);
}
