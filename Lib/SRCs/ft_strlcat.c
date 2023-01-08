/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:32:03 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:51:58 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

size_t	ft_strlcat(char	*dst, const	char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	j;
	size_t	nb;

	j = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (j);
	i = ft_strlen((const char *)dst);
	if (dstsize <= i || dstsize == 0)
		return (dstsize + j);
	nb = 0;
	while (src[nb] && nb < (dstsize - i) - 1)
	{
		dst[i + nb] = src[nb];
		nb++;
	}
	dst[i + nb] = '\0';
	return (i + j);
}
