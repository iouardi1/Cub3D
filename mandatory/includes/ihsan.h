/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihsan.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:32:33 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/11 23:20:47 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IHSAN_H
# define IHSAN_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "global_includes.h"
# include "settings.h"

int		check_maps_name(char *name);
int		free_double_array(char **arr);
int		last_line(char	*str);
int		check_borders(char *str);
int		check_roof_and_floor(char *str);
int		textures_parse(t_data *data, char *str);
int		check_ranges_supp1(char	*str);
int		valid_int(char **str);
int		check_identifier(t_data	*data, char	**str);
int		check_identifier1(t_data *data, char **str, char *p);
int		first_line_map(char *line);
int		textures_parse_supp2(char **p, int i);
int		textures_parse_supp1(t_data *data, char **p);
int		check_ranges(t_data *data, char l);
int		check_ranges_supp2(t_data *data, char **str, char l);
int		get_players_position(t_data	*data);
int		get_players_position_supp2(t_data *data, int i, int j, int p);
void	get_players_position_supp1(t_data *data, int i, int j);
int		get_out(t_data *game_data);
void	check_players_angle(t_data *data);
int		check_spaces(t_data	*data, char *str);
int		check_spaces_supp(char **p, int i, int j);
int		check_empty_lines(char *p);
int		a_valid_char(int i, size_t j, char **p);
void	print_error(char *err);
int		check_tabs(char *str);
void	check_path(char *pp, int i);

#endif
