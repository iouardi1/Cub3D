/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:16:10 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:51:58 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*start;
	char	*final;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, (int)*s1))
		s1++;
	if (*s1 == 0)
		return ((char *)ft_calloc(1, 1));
	start = (char *)s1;
	s1 = &start[ft_strlen(s1) - 1];
	while (*s1 && ft_strchr(set, (int)*s1))
		s1--;
	final = (char *)ft_calloc((size_t)(s1 - start) + 2, sizeof(char));
	if (!final)
		return (NULL);
	i = -1;
	while (&start[++i] != s1 + 1)
		final[i] = start[i];
	return (final);
}
