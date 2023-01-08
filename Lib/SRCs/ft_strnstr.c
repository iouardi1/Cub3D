/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:00:45 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/06 18:00:47 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	char *stop_p;

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
