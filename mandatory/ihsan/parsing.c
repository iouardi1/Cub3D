/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:59:23 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/02 16:17:46 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "ihsan.h"
// #include "includes/global_includes.h"
// #include "includes/parsing.h"
// #include "includes/settings.h"
// #include "includes/cub.h"


int	check_roof_and_floor(char *str)
{
	size_t        i;

    i = 0;
	while (str[i] && (str[i] == '1' || str[i] == ' ' || str[i] == '\t'))
		i++;
	if (i != ft_strlen(str))
		return (0);
	return (1);
}

int    check_borders(char *str)
{
	int		i = 0;
	int		j = 0;
	char	**p = ft_split(str, '\n');

	if (!check_roof_and_floor(p[0]))
		return (0);
	while (p[i])
		i++;
	if (!check_roof_and_floor(p[i - 1]))
		return (0);
	while (p[j] && (p[j][0] == '1' || p[j][0] == ' ' || p[j][0] == '\t'))
		j++;
	if (i != j)
    	return (0);
	j = 0;
	while (p[j] && (p[j][ft_strlen(p[j]) - 1] == '1' || p[j][ft_strlen(p[j]) - 1] == ' ' || p[j][ft_strlen(p[j]) - 1] == '\t'))
		j++;
	if (i != j)
    	return (0);
	return (1);
}

int	check_maps_name(char *name)
{
	char	**str;
	int        i = 0;

	if (!ft_strnstr(name, ".cub", ft_strlen(name)))
		return (0);
	str = ft_split(name, '.');
	while (str[i])
        i++;
	if (ft_strncmp(str[i - 1], "cub", ft_strlen(str[i - 1])))
	    return (0);
    return (1);
}

int	last_line(char	*str)
{
	size_t		i;

	i = ft_strlen(str);
	if (str[i - 1] == '1' || str[i - 1] == ' ' || str[i - 1] == '\t')
		return (1);
    return (0);
}

void	free_double_array(char **arr)
{
	int		i = 0;

	while (arr[i])
	{
		free(arr[i]);
        i++;
	}
	free(arr);
}

int	check_identifier(t_data	*data, char	**str)
{
	if (str[2])
		return (0);
	if (!ft_strncmp(str[0], "NO", ft_strlen(str[0])))
		data->vis_settings.no = ft_strdup(str[1]);
	else if(!ft_strncmp(str[0], "SO", ft_strlen(str[0])))
		data->vis_settings.so = ft_strdup(str[1]);
	else if(!ft_strncmp(str[0], "WE", ft_strlen(str[0])))
		data->vis_settings.we = ft_strdup(str[1]);
	else if(!ft_strncmp(str[0], "EA", ft_strlen(str[0])))
		data->vis_settings.ea = ft_strdup(str[1]);
	else if(!ft_strncmp(str[0], "F", ft_strlen(str[0])))
		data->vis_settings.f = ft_strdup(str[1]);
	else if(!ft_strncmp(str[0], "C", ft_strlen(str[0])))
		data->vis_settings.c = ft_strdup(str[1]);
	else
		return (0);
	return (1);
}

int	check_ranges(t_data *data)
{
	char	*str = ft_split(data->vis_settings.f, ',');
	
	while 
}

int	textures_parse(t_data *data, char *str)
{
	char	**p = ft_split(str, '\n');
	char	**pp;
	int		i = 0;

	while (p[i] && i < 6)
	{
		pp = ft_split(p[i], ' ');
		if (!check_identifier(data, pp))
		{
			free_double_array(pp);
			return (0);
		}
		free_double_array(pp);
		i++;
	}
	if (!check_ranges(data))
		return (0);
	return (1);
}

int parsing(t_data	*data, char **av)
{
	char	*line = NULL;
	char	*file = NULL;

	if (!check_maps_name(av[1]))
	{
		printf("Please enter a valid name\n");
		return (1);
	}
	int fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("file failed to be opened\n");
		return (1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		printf("empty map!\n");
		return (1);
	}
	file = ft_strjoin(file, line);
	while (1)
	{
		line = get_next_line(fd);
		file = ft_strjoin(file, line);
		if (!line)
			break;
	}
	if (!textures_parse(data, file))
	{
		printf("textures error\n");
		return (1);
	}
	// printf("SO: %s\n", data->vis_settings.so);
	// printf("NO: %s\n", data->vis_settings.no);
	// printf("EA: %s\n", data->vis_settings.ea);
	// printf("WE: %s\n", data->vis_settings.we);
	// printf("F:  %s\n", data->vis_settings.f);
	// printf("C:  %s\n", data->vis_settings.c);
	// if (!last_line(file))
	// {
	// 	printf("invalid map\n");
	// 	return (1);
	// }
	// if (!check_borders(file))
	// {
	// 	printf("invalid map\n");
	// 	return (1);
	// }
	return (0);
}