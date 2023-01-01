/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:02:43 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/11/06 22:24:33 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing_bonus.h"

//this fuction print the error string str in
//stderr and exit with exit_status
int	ft_print_error(char *str, int exit_status)
{
	ft_putstr_fd(str, 2);
	exit (exit_status);
}

void	extra_free(char *s1, char *s2, char flag)
{
	if (flag == FREE_FIRST || flag == FREE_ALL)
		free (s1);
	if (flag == FREE_SECOND || flag == FREE_ALL)
		free (s2);
}

char	*ft_extrajoin(char *s1, char *s2, char flag)
{
	char	*final;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		final = ft_strdup(s2);
		extra_free(s1, s2, flag);
		return (final);
	}
	if (!s2)
	{
		final = ft_strdup(s1);
		extra_free(s1, s2, flag);
		return (final);
	}
	final = ft_strjoin(s1, s2);
	extra_free(s1, s2, flag);
	return (final);
}

char	*ft_extratrim(char *str, char *set, char flag)
{
	char	*final;

	final = ft_strtrim(str, set);
	if (flag == FREE_FIRST)
		free(str);
	return (final);
}

int	check_for_char(char *map, char c)
{
	char	*ptr;

	ptr = ft_strchr(map, c);
	if (!ptr)
		return (0);
	if (*(ptr + 1) == c)
		return (1);
	return (check_for_char(ptr + 1, c));
}
