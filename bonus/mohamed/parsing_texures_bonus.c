/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texures_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:48:18 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/11/12 15:10:48 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing_bonus.h"

void	ft_check_empty(t_visual_settings *vis_settings, t_index i, \
							t_index j, char	**tmp)
{
	while (++i < 6)
	{
		if (((char **)vis_settings)[i] == NULL)
			ft_print_error("Error lack of needed texures\n", EXIT_FAILURE);
		if (i >= 4)
		{
			if (conditions(vis_settings, i))
				ft_print_error("Error in floor or ceiling color format\n", \
								EXIT_FAILURE);
			tmp = ft_split(((char **)vis_settings)[i], ',');
			(len_2d(tmp) != 3) && ft_print_error(\
				"Error the floor or ceiling color format\n", EXIT_FAILURE);
			j = 0;
			while (tmp[j])
			{
				((int **)vis_settings)[i + 2][j] = ft_atoi(tmp[j]);
				if (((int **)vis_settings)[i + 2][j] < 0 || \
					((int **)vis_settings)[i + 2][j] > 255)
					ft_print_error("Error in floor or ceiling color range\n", 2);
				free (tmp[j++]);
			}
			free(tmp);
		}
	}
}

void	set_names(char **elements)
{
	elements[0] = "NO ";
	elements[1] = "SO ";
	elements[2] = "WE ";
	elements[3] = "EA ";
	elements[4] = "F ";
	elements[5] = "C ";
	elements[6] = NULL;
}

t_index	ft_get_element_index(char **elements, char *str)
{
	t_index	i;

	i = 0;
	while (elements[i])
	{
		if (ft_strncmp(elements[i], str, 3 - (i > 3)) == MATCH)
			return (i);
		i++;
	}
	return (-1);
}

void	check_and_load_texture(t_visual_settings *vis_settings, \
								char **elements, char *str)
{
	t_index	i;

	i = ft_get_element_index(elements, str);
	if (i == -1 || wc(str, ' ') != 3 || ((char **)vis_settings)[i] || \
		ft_strchr(str, '\t') || ft_strchr(str, '\n'))
		ft_print_error("Error wrong map textures format\n", \
							EXIT_FAILURE);
	((char **)vis_settings)[i] = ft_strdup(ft_strrchr(str, ' ') + 1);
}

char	*parse_textures(t_visual_settings *vis_settings, \
									char **elements, int fd)
{
	char	*str;
	char	*old_str;

	set_names(elements);
	old_str = NULL;
	str = get_next_line(fd);
	if (!str)
		ft_print_error("Error empty map\n", EXIT_FAILURE);
	str = ft_extratrim(str, " \n", FREE_FIRST);
	while (str && ft_in_charset(str, " 01"))
	{
		if (*str != '\0')
			check_and_load_texture(vis_settings, elements, str);
		free (str);
		str = get_next_line(fd);
		free(old_str);
		old_str = ft_strdup(str);
		str = ft_extratrim(str, " \n", FREE_FIRST);
	}
	free (str);
	ft_check_empty(vis_settings, -1, 0, 0);
	return (old_str);
}
