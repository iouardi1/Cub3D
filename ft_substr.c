/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:58:41 by het-tale          #+#    #+#             */
/*   Updated: 2022/12/30 17:30:55 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	ft_cpy(char *substr, char const *s, size_t len, unsigned int start)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
		substr[i] = 0;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;

	if (!s)
		return (0);
	if (start < ft_strlen(s))
	{
		strlen = ft_strlen(s);
		if (strlen - start < len)
			len = strlen - start;
		substr = (char *)malloc((len + 1) * sizeof(char));
		if (!substr)
			return (0);
		ft_cpy(substr, s, len, start);
	}
	else
	{
		substr = (char *)malloc((1) * sizeof(char));
		substr[0] = '\0';
	}
	return (substr);
}
