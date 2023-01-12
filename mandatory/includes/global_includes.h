/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_includes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:34:09 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/11 15:57:54 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_INCLUDES_H
# define GLOBAL_INCLUDES_H

# define PI 3.141592653589793

// typedefs
typedef unsigned int	t_size;
typedef int				t_index;

// structs
typedef struct s_visual_settings
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		*fv;
	int		*cv;
}	t_visual_settings;

typedef struct s_map
{
	char	**map;
	t_size	length;
	t_size	height;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	t_img	*imgs;
	void	*mlx;
	void	*mlx_win;

}	t_mlx;

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	correct_dist;
}	t_coordinates;

typedef struct s_triangle_legs
{
	double	hypo;
	double	opposite;
	double	adjacent;
}	t_triangle_legs;

typedef struct s_angles
{
	double	angle;
	double	cos;
	double	sin;
	double	tan;
}	t_angles;

typedef struct s_intersections
{
	t_angles		angles_data;
	t_coordinates	h_cords;
	t_coordinates	v_cords;
	double			v_x_jump;
	double			v_y_jump;
	double			h_x_jump;
	double			h_y_jump;
	t_size			dof;
}	t_inter;

typedef struct s_player
{
	int		fixed_x;
	int		fixed_y;
	int		map_x;
	int		map_y;
	double	pixel_x;
	double	pixel_y;
	double	angle;
	int		is_left;
	int		is_right;
	int		is_up;
	int		is_down;
	int		is_rotate_left;
	int		is_rotate_right;
}	t_player;

typedef struct s_screen
{
	int		start_x;
	int		start_y;
}	t_screen;

typedef struct s_data
{
	t_visual_settings	vis_settings;
	t_map				map;
	t_mlx				mlx_settings;
	t_player			player;
	t_screen			screen;
	int					no_c;
	int					so_c;
	int					ea_c;
	int					we_c;
	int					f_c;
	int					c_c;
}	t_data;

t_coordinates	get_wall_intersection(t_data *game_data, double angle);
int				get_texture(t_coordinates x_y_inter, t_angles angles);
int				get_pixel_color(double x_or_y_inter, \
	t_coordinates coords, double height);
double			get_wall_start(double height);
double			get_wall_end(double height);
double			get_wall_height(double dist);
void			index_to_img(t_data *game_data, int i, \
	int *width, int *height);
t_coordinates	to_coords(double x, double y);
t_angles		to_angles(double deg);
void			rotate_left(t_data *game_data);
void			rotate_right(t_data *game_data);
int				should_move(t_data *game_data, int x, int y);
void			move_up(t_data *game_data);
void			move_down(t_data *game_data);
void			move_right(t_data *game_data);
void			move_left(t_data *game_data);
void			my_mlx_pixel_put(t_mlx *game_data, \
	t_coordinates coords, int color);
void			init_mlx_settings(t_mlx *mlx_settings);
int				key_down(int key, t_data *game_data);
int				key_up(int key, t_data *game_data);
void			draw_sky(t_data *game_data, t_coordinates coords);
void			draw_floor(t_data *game_data, t_coordinates coords);
void			build_wall(t_data *game_data, t_coordinates coords, \
	t_coordinates inter, double deg);
void			ray_casting(t_data *game_data);
int				loop(t_data *game_data);
void			textures_init(t_data *game_data);
void			to_3d(t_data *game_data);

/*----------------*/

int				touch_wall(t_data *game_data, int pixel_x, int pixel_y);
void			first_h_inter(t_coordinates *player, t_angles angles);
void			first_v_inter(t_coordinates *player, t_angles angles);
t_coordinates	last_h_inter(t_data *game_data, t_coordinates last_h_inter, \
						t_angles angles);
t_coordinates	last_v_inter(t_data *game_data, t_coordinates last_v_inter, \
						t_angles angles);
t_coordinates	ray_cast(t_data *game_data, double degree);
/*-----------------*/

void			get_short_dist(t_player *player, t_inter *inter, \
	t_coordinates *cords, double angle);
int				get_out(t_data *game_data);
int				len_2d(char **tab);
char			*conditions(t_visual_settings *vis_settings, t_index i);
double			get_distance(t_data *game_data, t_coordinates coords);
//
int				parsing(t_data	*data, char **av);

#endif
