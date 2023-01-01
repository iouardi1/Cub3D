/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:15:43 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/11/12 14:55:17 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	len_2d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	get_out(t_data *game_data)
{
	free(game_data->vis_settings.cv);
	free(game_data->vis_settings.fv);
	free(game_data);
	exit (EXIT_SUCCESS);
}

void	parse_map(int fd, char *str, t_data	*data)
{
	if (!str)
		ft_print_error("Error no map grid\n", EXIT_FAILURE);
	str = get_map(fd, str, &data->map);
	if (str[0] == '\n' || *(ft_strchr(str, '\0') - 1) == '\n' || \
							check_for_char(str, '\n'))
		ft_print_error("Error wrong map grid format\n", \
										EXIT_FAILURE);
	size_correction(ft_split(str, '\n'), &data->map);
	free(str);
	map_error_checking(data);
}

int	check_name(char *map_name)
{
	const char	*ext;
	char		*tmp;

	ext = ".cub";
	tmp = map_name;
	map_name = ft_strrchr(map_name, '.');
	if (tmp == map_name || !map_name)
		ft_print_error("Error file with no extention\n", EXIT_FAILURE);
	return (ft_strncmp(map_name, ext, 5));
}

//loads the content of the file .cub in the struct
t_exit_status	parsing(t_data	*game_data, char **av)
{
	char	*elements[7];
	int		fd;
	char	*str;

	if (check_name(av[1]) != MATCH)
		ft_print_error("Error in map file extention\n", EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_print_error("Error file doesn't exist\n", EXIT_FAILURE);
	str = parse_textures(&game_data->vis_settings, elements, fd);
	parse_map(fd, str, game_data);
	return (EXIT_SUCCESS);
}
