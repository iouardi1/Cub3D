/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:44:53 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/08 04:44:52 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;

	if (!s1 || !s2)
		return (NULL);
	arr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	arr[0] = '\0';
	ft_strlcat(arr, s1, ft_strlen(s1) + 1);
	ft_strlcat(arr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (arr);
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char	*arr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	arr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	arr[0] = '\0';
	ft_strlcat(arr, s1, ft_strlen(s1) + 1);
	ft_strlcat(arr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (arr);
}
