/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:16:48 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/11 16:58:05 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ihsan.h"

int	check_roof_and_floor(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == '1' || str[i] == ' '))
		i++;
	if (i != ft_strlen(str))
		return (0);
	return (1);
}

int	check_borders(char *str)
{
	int		i;
	int		j;
	char	**p;

	i = 0;
	j = 0;
	p = ft_split(str, '\n');
	while (p[i])
		i++;
	if (!check_roof_and_floor(p[0]) || !check_roof_and_floor(p[i - 1]))
	{
		free_double_array(p);
		return (0);
	}
	while (p[j] && (p[j][0] == '1' || p[j][0] == ' ') && \
		(p[j][ft_strlen(p[j]) - 1] == '1' \
		|| p[j][ft_strlen(p[j]) - 1] == ' '))
		j++;
	if (i != j)
	{
		free_double_array(p);
		return (0);
	}
	free_double_array(p);
	return (1);
}

int	check_maps_name(char *name)
{
	char	**str;
	int		i;

	i = 0;
	if (!ft_strnstr(name, ".cub", ft_strlen(name)))
		return (0);
	str = ft_split(name, '.');
	while (str[i])
		i++;
	if (ft_strncmp(str[i - 1], "cub", ft_strlen(str[i - 1])))
	{
		free_double_array(str);
		return (0);
	}
	free_double_array(str);
	return (1);
}

int	last_line(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '1' || str[i - 1] == ' ')
		return (1);
	return (0);
}

void	free_double_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
