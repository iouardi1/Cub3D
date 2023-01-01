/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:02:26 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:51:58 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*final;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	final = (char *)ft_calloc(s1len + s2len + 1, sizeof(char));
	if (final == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		final[i] = s1[i];
	i--;
	while (s2[(++i) - (int)s1len])
		final [i] = s2[i - (int)s1len];
	return (final);
}