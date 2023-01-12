/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:54:00 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/08 03:56:49 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*ptr;

	ptr = (char *)src;
	if (!dstsize)
		return (ft_strlen(src));
	while (*ptr && (ptr - src) / sizeof(char) < dstsize - 1)
	{
		*dst++ = *(char *)ptr++;
	}
	*dst = '\0';
	return (ft_strlen(src));
}
