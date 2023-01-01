/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:59:23 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/01 15:33:37 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "ihsan.h"


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

int main(int ac, char **av)
{
	char	*line = NULL;
	char	*file = NULL;

	if (ac != 2)
	{
		printf("Please enter one valid argument\n");
		return (1);
	}
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
	while (1)
	{
		file = ft_strjoin(file, line);
		line = get_next_line(fd);
		if (!line)
			break;
	}
	if (!last_line(file))
	{
		printf("invalid map\n");
		return (1);
	}
	if (!check_borders(file))
	{
		printf("invalid map\n");
		return (1);
	}
	
}