/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:02:19 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/08 04:53:58 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_LIB_H
# define CUB_LIB_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include <float.h>
# include <sys/errno.h>

# include "SRCs/libft.h"
# define BUFFER_SIZE 13

//get next line
char			*get_next_line(int fd);
void			*ft_memcpy1(void *dest, const void *src, size_t n);
char			*ft_strjoin2(char const *s1, char const *s2);
size_t			ft_strlcat1(char *dst, const char *src, size_t size);
char			*ft_strchr1(const char *str, int c);
char			*ft_strdup1(const char *s1);
//-------------

#endif