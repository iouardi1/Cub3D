/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:25:28 by achedmi           #+#    #+#             */
/*   Updated: 2022/11/08 00:26:28 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/settings.h"

void	my_mlx_pixel_put(t_mlx *game_data, t_coordinates coords, int color)
{
	char	*dst;

	if (coords.x < 0 || coords.x >= WINDOW_W || \
		coords.y < 0 || coords.y >= WINDOW_H)
		return ;
	dst = game_data->imgs[0].addr + ((int)coords.y * \
	game_data->imgs[0].line_length +(int)coords.x * \
	(game_data->imgs[0].bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_mlx_settings(t_mlx *mlx_settings)
{
	mlx_settings->mlx = mlx_init();
	mlx_settings->mlx_win = mlx_new_window(mlx_settings->mlx, \
		WINDOW_W, WINDOW_H, "Cub3D");
	mlx_settings->imgs = malloc(sizeof(t_img) * 5);
	mlx_settings->imgs[0].img = mlx_new_image(mlx_settings->mlx, \
		WINDOW_W, WINDOW_H);
	mlx_settings->imgs[0].addr = mlx_get_data_addr(mlx_settings->imgs[0].img, \
	&mlx_settings->imgs[0].bits_per_pixel, &mlx_settings->imgs[0].line_length, \
	&mlx_settings->imgs[0].endian);
}
