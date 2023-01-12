/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 04:35:17 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/08 04:35:21 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

// /**
//  * @brief this function reallocat memory equale to ptr_size + add_size and
//  * copy the old data into the new one and free ptr.
//  * it uses calloc to allocate the new memory region.
//  * 
//  * 
//  * @param ptr 		old buffer (freed after being copied in the new one)
//  * @param ptr_size 	old buffer size
//  * @param add_size 	how many bytes to add to in the new allocated reagion
//  * @return void* 	the newly allocated memory space
//  */
void	*ft_realloc(void *ptr, size_t ptr_size, size_t add_size)
{
	void	*final;

	final = ft_calloc(1, ptr_size + add_size);
	ft_memcpy(final, ptr, ptr_size);
	free (ptr);
	return (final);
}
