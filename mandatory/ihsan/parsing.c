/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:59:23 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/11 17:15:14 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ihsan.h"

void	print_error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
}

int	check_tabs(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			print_error("invalid map\n");
			exit (1);
		}
		i++;
	}
	return (0);
}

char	*parsing_supp2(char *file, char *line, int fd)
{
	char	*tmp;

	tmp = file;
	file = ft_strjoin(file, line);
	free(tmp);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		tmp = file;
		file = ft_strjoin1(tmp, line);
		free(tmp);
		if (!line)
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (file);
}

char	*parsing_supp1(char *file, char **av)
{
	char	*line;
	int		fd;

	line = NULL;
	if (!check_maps_name(av[1]))
	{
		print_error("Please enter a valid name\n");
		return (NULL);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		print_error("file failed to be opened\n");
		return (NULL);
	}
	line = get_next_line(fd);
	if (!line)
	{
		print_error("empty map!\n");
		free(line);
		return (NULL);
	}
	file = parsing_supp2(file, line, fd);
	return (file);
}

int	parsing(t_data	*data, char **av)
{
	char	*file;
	int		i;

	file = ft_strdup("");
	file = parsing_supp1(file, av);
	if (!file || !textures_parse(data, file))
	{
		print_error("textures error\n");
		return (1);
	}
	i = first_line_map(file);
	if (!last_line(file + i) || !check_borders(file + i) || \
		!check_spaces(data, file + i) || !get_players_position(data))
	{
		print_error("invalid map\n");
		return (1);
	}
	return (0);
}
