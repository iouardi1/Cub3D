/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:02:48 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/06 18:02:48 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../cub_lib.h"

void	*ft_calloc(size_t	count,	size_t	size)
{
	void	*tmp;

	tmp = malloc(count * size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
