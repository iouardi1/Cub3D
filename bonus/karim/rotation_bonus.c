/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:21:41 by achedmi           #+#    #+#             */
/*   Updated: 2022/11/06 22:23:55 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/settings_bonus.h"

void	rotate_left(t_data	*game_data)
{
	game_data->player.angle += ROTAION_DEG;
	if (game_data->player.angle > 2 * M_PI)
		game_data->player.angle -= 2 * M_PI;
}

void	rotate_right(t_data	*game_data)
{
	game_data->player.angle -= ROTAION_DEG;
	if (game_data->player.angle < 0)
		game_data->player.angle += 2 * M_PI;
}
