/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:09:46 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:51:58 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*stop_p;

	stop_p = (char *)haystack + len;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && haystack != stop_p)
	{
		if (*haystack == *needle)
		{
			while (needle[i] == haystack[i] && &haystack[i] != stop_p)
			{
				i++;
				if (needle[i] == '\0')
					return ((char *)haystack);
			}
			if (haystack[i] != needle[i])
				i = 0;
		}
		haystack++;
	}
	return (0);
}
