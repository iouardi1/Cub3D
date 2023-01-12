/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:04:30 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/08 03:54:03 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;

	if (!dest && !src)
		return (0);
	temp = dest;
	while (n--)
		*temp++ = *(unsigned char *)src++;
	return (dest);
}
