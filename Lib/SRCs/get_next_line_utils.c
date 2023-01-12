/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 04:25:11 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/08 04:30:12 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

char	*ft_strchr1(const char *str, int c)
{
	size_t	i;
	size_t	j;

	j = -1;
	i = ft_strlen(str);
	while (++j < i)
	{
		if (str[j] == (char)c)
			return ((char *)(str + j + 1));
	}
	if (str[j] == c)
		return ((char *)(str + j));
	return (NULL);
}

size_t	ft_strlcat1(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	dst_length;
	size_t	dsst_length;
	size_t	i;

	if (!dst && !size)
		return (ft_strlen(src));
	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	dsst_length = src_length;
	i = 0;
	if (dst_length < size)
		dsst_length += dst_length;
	else
		dsst_length += size;
	while (src[i] && dst_length + 1 < size)
	{
		dst[dst_length++] = src[i++];
	}
	dst[dst_length] = '\0';
	return (dsst_length);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*arr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup1(s2));
	if (!s2)
		return (ft_strdup1(s1));
	arr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	arr[0] = '\0';
	ft_strlcat1(arr, s1, ft_strlen(s1) + 1);
	ft_strlcat1(arr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (arr);
}

void	*ft_memcpy1(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;

	if (!dest && !src)
		return (0);
	temp = dest;
	while (n--)
		*temp++ = *(unsigned char *)src++;
	return (dest);
}
