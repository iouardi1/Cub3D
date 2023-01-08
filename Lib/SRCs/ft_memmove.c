/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:53:30 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:51:58 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

void	*ft_memmove(void *dst, const void *src,	size_t len)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (src < dst && src + len > dst)
	{
		while (--len > 0)
			tmp[len] = ((char *)src)[len];
		if (len == 0)
			tmp[len] = ((char *)src)[len];
	}
	else
	{
		while (i < len)
		{
			tmp[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
