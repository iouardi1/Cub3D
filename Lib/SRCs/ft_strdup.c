/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:26:24 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:51:58 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*cpy;

	cpy = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (cpy == NULL)
		return (0);
	i = 0;
	while (*s1)
	{
		cpy[i++] = *s1;
		s1++;
	}
	return (cpy);
}
