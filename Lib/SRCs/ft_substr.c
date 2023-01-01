/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:05:19 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:51:58 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	length = ft_strlen(s);
	if ((size_t)start >= length)
		length = 1;
	else if (length - (size_t)start > len)
		length = len + 1;
	else if (length - (size_t)start <= len)
		length = length - (size_t)start + 1;
	ptr = (char *)ft_calloc(length, 1);
	if (ptr == NULL)
		return (NULL);
	while (i < length - 1)
	{
		ptr[i] = s[i + (size_t)start];
		i++;
	}
	return (ptr);
}
