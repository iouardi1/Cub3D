/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:25:47 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/07 23:54:02 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ihsan.h"

int	a_valid_char(int i, size_t j, char **p)
{
	if (p[i][j + 1] != '1' && p[i][j + 1] != '0' && p[i][j + 1] != 'S' \
		&& p[i][j + 1] != 'N' && p[i][j + 1] != 'W' && p[i][j + 1] != 'E')
			return (0);
	if ((p[i][j - 1] != '1' && p[i][j - 1] != '0' && p[i][j - 1] != 'S' \
		&& p[i][j - 1] != 'N' && p[i][j - 1] != 'W' && p[i][j - 1] != 'E'))
		return (0);
	if (j >= ft_strlen(p[i + 1]) || (p[i + 1][j] != '1' && p[i + 1][j] != '0' \
		&& p[i + 1][j] != 'S' && p[i + 1][j] != 'N' && p[i + 1][j] != 'W' \
			&& p[i + 1][j] != 'E'))
				return (0);
	if (j >= ft_strlen(p[i - 1]) || (p[i - 1][j] != '1' && p[i - 1][j] != '0' \
		&& p[i - 1][j] != 'S' && p[i - 1][j] != 'N' && p[i - 1][j] != 'W' \
			&& p[i - 1][j] != 'E'))
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

int    check_spaces_supp(char **p, int i, int j)
{
	j = 0;
	while (p[i][j])
	{
		if (p[i][j] == '0' && (!a_valid_char(i, j, p)))
			return (0);
		if ((p[i][j] == 'S' || p[i][j] == 'N' || p[i][j] == 'W' || p[i][j] == 'E') \
			&& (!a_valid_char(i, j, p)))
			return (0);
		j++;
	}
	return (j);
}

int check_spaces(t_data	*data, char *str)
{
	size_t		i;
	size_t		j;
	size_t		length;
	char		**p;

	if (!check_empty_lines(str))
		return (0);
	p = ft_split(str, '\n');
	i = 0;
	length = 0;
	while (p[i])
    {
		j = check_spaces_supp(p, i, j); 
		if (!j)
			return (0);
		if (length < j)
			length = j;
		i++;
	}
	data->map.map = p;
	data->map.height = i;
	data->map.length = length;
	return (1);
}
