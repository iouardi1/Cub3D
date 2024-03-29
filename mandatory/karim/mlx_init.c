/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:04:08 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/08 04:57:00 by iouardi          ###   ########.fr       */
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
