/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:21:08 by achedmi           #+#    #+#             */
/*   Updated: 2022/11/06 22:23:40 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/settings_bonus.h"

int	key_down(int key, t_data	*game_data)
{
	if (key == 13)
		game_data->player.is_up = 1;
	else if (key == 0)
		game_data->player.is_left = 1;
	else if (key == 1)
		game_data->player.is_down = 1;
	else if (key == 2)
		game_data->player.is_right = 1;
	else if (key == 124)
		game_data->player.is_rotate_left = 1;
	else if (key == 123)
		game_data->player.is_rotate_right = -1;
	else if (key == 53)
		exit(0);
	return (0);
}

int	key_up(int key, t_data	*game_data)
{
	if (key == 13)
		game_data->player.is_up = 0;
	else if (key == 0)
		game_data->player.is_left = 0;
	else if (key == 1)
		game_data->player.is_down = 0;
	else if (key == 2)
		game_data->player.is_right = 0;
	else if (key == 124)
		game_data->player.is_rotate_left = 0;
	else if (key == 123)
		game_data->player.is_rotate_right = 0;
	return (0);
}
