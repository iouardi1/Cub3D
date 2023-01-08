/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:24:42 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:52:16 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

char	*get_strjoin(char **s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*final;
	int		i;

	if (*s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	s1len = ft_strlen(*s1);
	s2len = ft_strlen(s2);
	final = (char *)ft_calloc(s1len + s2len + 1, sizeof(char));
	if (final == NULL)
		return (NULL);
	i = -1;
	while (s1[0][++i])
		final[i] = s1[0][i];
	i--;
	while (s2[(++i) - (int)s1len])
		final [i] = s2[i - (int)s1len];
	free(*s1);
	*s1 = NULL;
	return (final);
}

char	*handel_the_shit(char	**saved)
{
	char	*final;
	char	*tp;
	int		i;

	i = ft_strlen(*saved);
	final = NULL;
	if (ft_strchr(*saved, '\n'))
	{
		final = ft_substr(*saved, 0, ft_strchr(*saved, '\n') - *saved + 1);
		tp = *saved;
		*saved = ft_substr(*saved, ft_strchr(*saved, '\n') - *saved + 1, i);
		free_it(&tp);
		return (final);
	}
	else
	{
		final = ft_strdup(*saved);
		free_it(saved);
		return (final);
	}
}

char	*free_it(char	**target)
{
	free(*target);
	*target = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		str[BUFFER_SIZE + 1];
	static char	*saved;
	char		*final;
	int			re_ad;

	re_ad = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved)
		saved = ft_strdup("");
	while (re_ad > 0 && !ft_strchr(saved, '\n'))
	{
		re_ad = read(fd, str, BUFFER_SIZE);
		if (re_ad < 0)
			return (free_it(&saved));
		str[re_ad] = '\0';
		saved = get_strjoin(&saved, str);
	}
	final = handel_the_shit(&saved);
	if (final && !ft_strlen(final))
		free_it(&final);
	return (final);
}
