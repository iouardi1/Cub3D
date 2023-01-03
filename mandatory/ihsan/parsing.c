/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:59:23 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/03 21:15:56 by iouardi          ###   ########.fr       */
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
	
	i = 0;
	while (str[i])
        i++;
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

int	valid_int(char **str)
{
	int		i = 0;
	int		j;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
		    if (!ft_isdigit(str[i][j]))
                return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_ranges(t_data *data, char l)
{
	char	**str;
	int		i = 0;
	int		v = 0;

	while (data->vis_settings.f[i])
	{
		if (data->vis_settings.f[i] == ',')
		{
			v++;
			if (!ft_isdigit(data->vis_settings.f[i + 1]))
				return (0);
		}
		i++;
	}
	if (v > 2)
		return (0);
	v = 0;
	i = 0;
	while (data->vis_settings.c[i])
	{
		if (data->vis_settings.c[i] == ',')
		{
			v++;
			if (!ft_isdigit(data->vis_settings.c[i + 1]))
				return (0);
		}
		i++;
	}
	if (v > 2)
		return (0);
	if (l == 'f')
		str = ft_split(data->vis_settings.f, ',');
	else
		str = ft_split(data->vis_settings.c, ',');
	if (!valid_int(str))
	    return (0);
	i = 0;
	while (str[i])
	{
		if (str[i][0] == '\0')
			return (0);
		if(ft_atoi(str[i]) > 255 || ft_atoi(str[i]) < 0)
			return (0);
		if (l == 'f')
			data->vis_settings.fv[i] = ft_atoi(str[i]);
		else if (l == 'c')
			data->vis_settings.cv[i] = ft_atoi(str[i]);
		i++;
	}
	return (1);
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
	if (!check_ranges(data, 'f') || !check_ranges(data, 'c'))
		return (0);
	return (1);
}

int	first_line_map(char *line)
{
	int		i = 0;

	while (line[i] && line[i + 1])
	{
		if (line[i] == '\n' && line[i + 1] == '1')
		    return (i + 1);
        i++;
	}
	return (0);
}

int	map_characters(t_data *data, char *str)
{
	int		i = 0;
	int		p = 0;

	(void)data;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'E' && str[i] != 'S' && str[i] != 'W' && str[i] != ' ' && str[i] != '\n')
			return (0);
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'W')
			p++;
		i++;
	}
	if (p != 1)
		return (0);
	return (1);
}

int	a_valid_char(int i, size_t j, char **p)
{
	if (p[i][j + 1] != '1' && p[i][j + 1] != '0' && p[i][j + 1] != 'S' && p[i][j + 1] != 'N' && p[i][j + 1] != 'W' && p[i][j + 1] != 'E')
		return (0);
	if ((p[i][j - 1] != '1' && p[i][j - 1] != '0' && p[i][j - 1] != 'S' && p[i][j - 1] != 'N' && p[i][j - 1] != 'W' && p[i][j - 1] != 'E'))
		return (0);
	if (j >= ft_strlen(p[i + 1]) || (p[i + 1][j] != '1' && p[i + 1][j] != '0' && p[i + 1][j] != 'S' && p[i + 1][j] != 'N' && p[i + 1][j] != 'W' && p[i + 1][j] != 'E'))
		return (0);
	if (j >= ft_strlen(p[i - 1]) || (p[i - 1][j] != '1' && p[i - 1][j] != '0' && p[i - 1][j] != 'S' && p[i - 1][j] != 'N' && p[i - 1][j] != 'W' && p[i - 1][j] != 'E'))
		return (0);
	return (1);
}

int	check_empty_lines(char *p)
{
	int		i = 0;

	while (p[i])
	{
		if (p[i] == '\n' && p[i + 1] == '\n')
            return (0);
		i++;
	}
	return (1);
}

int check_spaces(char *str)
{
	if (!check_empty_lines(str))
		return (0);
	char **p = ft_split(str, '\n');

	int		i = 0;
	size_t		j;
	while (p[i])
    {
		j = 0;
		while (p[i][j])
		{
			if (p[i][j] == '0' && (!a_valid_char(i, j, p)))
				return (0);
			if ((p[i][j] == 'S' || p[i][j] == 'N' || p[i][j] == 'W' || p[i][j] == 'E') && (!a_valid_char(i, j, p)))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int parsing(t_data	*data, char **av)
{
	char	*line = NULL;
	char	*file = NULL;
	int		i;

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
	i = first_line_map(file);
	if (!last_line(file + i))
	{
		printf("invalid map1\n");
		return (1);
	}
	if (!check_borders(file + i))
	{
		printf("invalid map2\n");
		return (1);
	}
	if (!map_characters(data, file + i))
	{
		printf("invalid map3\n");
        return (1);
	}
	if (!check_spaces(file + i))
	{
		printf("invalid map4\n");
        return (1);
	}
	return (0);
}