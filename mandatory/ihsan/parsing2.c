/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:16:59 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/07 23:21:39 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ihsan.h"

static	int	no_c = 0;
static	int	so_c = 0;
static	int	ea_c = 0;
static	int	we_c = 0;
static	int	f_c = 0;
static	int	c_c = 0;

int	check_identifier1(t_data *data, char **str)
{
	if(str[0] && !ft_strncmp(str[0], "F", ft_strlen(str[0])))
	{
		f_c += 1;
		data->vis_settings.f = ft_strdup(str[1]);
	}
	else if(str[0] && !ft_strncmp(str[0], "C", ft_strlen(str[0])))
	{
		c_c += 1;
		data->vis_settings.c = ft_strdup(str[1]);
	}
	else
		return (0);
	return (1);
}

int	check_identifier(t_data	*data, char	**str)
{
	if (str[2])
		return (0);
	if (!ft_strncmp(str[0], "NO", ft_strlen(str[0])))
	{
		no_c += 1;
		data->vis_settings.no = ft_strdup(str[1]);
	}
	else if(!ft_strncmp(str[0], "SO", ft_strlen(str[0])))
	{
		so_c += 1;
		data->vis_settings.so = ft_strdup(str[1]);
	}
	else if(!ft_strncmp(str[0], "WE", ft_strlen(str[0])))
	{
		we_c += 1;
		data->vis_settings.we = ft_strdup(str[1]);
	}
	else if(!ft_strncmp(str[0], "EA", ft_strlen(str[0])))
	{
		ea_c += 1;
		data->vis_settings.ea = ft_strdup(str[1]);
	}
	else if (!check_identifier1(data, str))
		return (0);
	return (1);
}

int	valid_int(char **str)
{
	int		i;
	int		j;

	i = 0;
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

int	check_ranges_supp1(char	*str)
{
	int		i;
	int		v;

	i = 0;
	v = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			v++;
			if (!ft_isdigit(str[i + 1]))
				return (0);
		}
		i++;
	}
	if (v != 2)
		return (0);
	return (1);
}

int	textures_parse(t_data *data, char *str)
{
	char	**p;
	int		i;

	p = ft_split(str, '\n');
	i = textures_parse_supp1(data, p);
	if (!i)
	{
		free_double_array(p);
		return (0);
	}
	if (!textures_parse_supp2(p, i))
	{
		free_double_array(p);
		return (0);
	}
	free_double_array(p);
	if (no_c != 1 || so_c != 1 || we_c != 1 || ea_c != 1 || f_c != 1 || c_c != 1)
		return (0);
	if (!check_ranges(data, 'f') || !check_ranges(data, 'c'))
		return (0);
	return (1);
}