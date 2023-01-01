/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:25:06 by achedmi           #+#    #+#             */
/*   Updated: 2022/11/06 22:23:04 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "global_includes_bonus.h"
# include "cub_bonus.h"

t_exit_status	parsing(t_data	*gamed_data, char **av);
void			set_names(char **elements);
t_index			ft_get_element_index(char **elements, char *str);
char			*ft_extratrim(char *str, char *set, char flag);
int				check_for_char(char *map, char c);
int				ft_print_error(char *str, int exit_status);
void			ft_check_empty(t_visual_settings *vis_settings, t_index i, \
t_index j, char	**tmp);
char			*parse_textures(t_visual_settings *vis_settings, \
char **elements, int fd);
void			extra_free(char *s1, char *s2, char flag);
char			*ft_extrajoin(char *s1, char *s2, char flag);
char			*get_map(int fd, char *str, t_map *map);
void			size_correction(char **old_map, t_map *map);
void			init_player_data(t_data *data, t_index i, t_index j, \
int player_count);
int				check_map_body(t_data *data, t_index i);
void			map_error_checking(t_data *data);
void			parse_map(int fd, char *str, t_data	*data);
int				check_name(char *map_name);

#endif