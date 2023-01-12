/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:22:43 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/12 05:55:13 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ihsan.h"

int	check_ranges_supp2(t_data *data, char **str, char l)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '\0')
			return (0);
		if (ft_atoi(str[i]) > 255 || ft_atoi(str[i]) < 0)
			return (0);
		if (l == 'f')
			data->vis_settings.fv[i] = ft_atoi(str[i]);
		else if (l == 'c')
			data->vis_settings.cv[i] = ft_atoi(str[i]);
		i++;
	}
	return (1);
}

int	check_ranges(t_data *data, char l)
{
	char	**str;

	if (!check_ranges_supp1(data->vis_settings.f) || \
		!check_ranges_supp1(data->vis_settings.c))
		return (0);
	if (l == 'f')
		str = ft_split(data->vis_settings.f, ',');
	else
		str = ft_split(data->vis_settings.c, ',');
	if (!valid_int(str))
	{
		free_double_array(str);
		return (0);
	}
	if (!check_ranges_supp2(data, str, l))
	{
		free_double_array(str);
		return (0);
	}
	free_double_array(str);
	return (1);
}

int	textures_parse_supp1(t_data *data, char **p)
{
	int		i;
	int		j;
	char	**pp;
	char	*tmp;

	i = 0;
	j = 0;
	while (p[j] && i < 6 && !check_tabs(p[j]))
	{
		tmp = p[j];
		p[j] = ft_strtrim(tmp, " ");
		free (tmp);
		pp = ft_split1(p[j], ' ');
		if (!pp[0])
		{
			j++;
			free_double_array(pp);
			continue ;
		}
		if (!pp[1] || !check_identifier(data, pp))
			return (free_double_array(pp));
		free_double_array(pp);
		i++;
		j++;
	}
	return (j);
}

int	textures_parse_supp2(char **p, int i)
{
	char	*ppp;

	while (p[i])
	{
		ppp = ft_strtrim(p[i], " ");
		if (ppp[0] && ppp[0] != '1')
		{
			free(ppp);
			return (0);
		}
		i++;
		free(ppp);
	}
	return (1);
}

int	first_line_map_supp(char *line, int i)
{
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			return (i);
		else
			return (0);
		i++;
	}
	return (0);
}

int	first_line_map(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i + 1])
	{
		if (line[i] == '\n' && first_line_map_supp(line, i + 1))
			return (first_line_map_supp(line, i + 1));
		i++;
	}
	return (0);
}
