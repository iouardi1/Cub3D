/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:43:32 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/08 04:46:41 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
