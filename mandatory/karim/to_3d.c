/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:50:57 by achedmi           #+#    #+#             */
/*   Updated: 2022/11/08 00:22:29 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/settings.h"

void	build_wall(t_data	*game_data, t_coordinates coords, \
t_coordinates inter, double deg)
{
	double			y_to;
	t_coordinates	x_y_inter;
	double			height;
	t_angles		angles;

	height = coords.y;
	coords.y = get_wall_start(height);
	y_to = get_wall_end(height);
	angles = to_angles(deg);
	x_y_inter.x = fmod(inter.x, BLOCK_SIZE);
	x_y_inter.y = fmod(inter.y, BLOCK_SIZE);
	draw_sky(game_data, coords);
	while (coords.y < y_to)
	{
		my_mlx_pixel_put(&game_data->mlx_settings, coords, \
		((int *)game_data->mlx_settings.imgs \
		[get_texture(x_y_inter, angles)].addr) \
		[get_pixel_color(x_y_inter.x + x_y_inter.y, coords, height)]);
		coords.y++;
	}
	draw_floor(game_data, coords);
}

void	ray_casting(t_data	*game_data)
{
	double			deg;
	double			inc;
	double			x;
	double			height;
	t_coordinates	inter;

	deg = game_data->player.angle - ((PI / 3) / 2);
	inc = (PI / 3) / WINDOW_W;
	x = WINDOW_W - 1;
	while (x >= 0)
	{
		inter = get_wall_intersection(game_data, deg);
		height = get_wall_height(inter.correct_dist);
		build_wall(game_data, to_coords(x, height), inter, deg);
		deg += inc * cos(game_data->player.angle - deg);
		x -= 1;
	}
}

int	loop(t_data	*game_data)
{
	int static	i = 0;

	if (i++ % 100000 == 0)
	{
		if (game_data->player.is_up)
			move_up(game_data);
		if (game_data->player.is_right)
			move_right(game_data);
		if (game_data->player.is_down)
			move_down(game_data);
		if (game_data->player.is_left)
			move_left(game_data);
		if (game_data->player.is_rotate_left)
			rotate_right(game_data);
		if (game_data->player.is_rotate_right)
			rotate_left(game_data);
		i = 0;
		ray_casting(game_data);
		mlx_put_image_to_window(game_data->mlx_settings.mlx, \
		game_data->mlx_settings.mlx_win, \
		game_data->mlx_settings.imgs[0].img, 0, 0);
	}
	return (0);
}

void	textures_init(t_data	*game_data)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	while (i++ < 4)
	{
		index_to_img(game_data, i, &width, &height);
		if (!game_data->mlx_settings.imgs[i].img)
		{
			ft_putstr_fd("Wrong texture\n", 2);
			exit (1);
		}
		game_data->mlx_settings.imgs[i].addr = mlx_get_data_addr \
		(game_data->mlx_settings.imgs[i].img, \
		&game_data->mlx_settings.imgs[i].bits_per_pixel, \
		&game_data->mlx_settings.imgs[i].line_length, \
		&game_data->mlx_settings.imgs[i].endian);
	}
}

void	to_3d(t_data	*game_data)
{
	init_mlx_settings(&game_data->mlx_settings);
	textures_init(game_data);
	game_data->player.pixel_x = (game_data->player.map_x * BLOCK_SIZE);
	game_data->player.pixel_y = (game_data->player.map_y * BLOCK_SIZE);
	mlx_put_image_to_window(game_data->mlx_settings.mlx, \
	game_data->mlx_settings.mlx_win, game_data->mlx_settings.imgs[0].img, 0, 0);
	mlx_hook(game_data->mlx_settings.mlx_win, 02, 1L << 0, key_down, game_data);
	mlx_hook(game_data->mlx_settings.mlx_win, 17, 0, get_out, game_data);
	mlx_hook(game_data->mlx_settings.mlx_win, 03, 1L << 1, key_up, game_data);
	mlx_loop_hook(game_data->mlx_settings.mlx, loop, game_data);
	mlx_loop(game_data->mlx_settings.mlx);
}
