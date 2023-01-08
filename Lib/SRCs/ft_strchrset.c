/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:08:11 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/16 00:08:21 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

//this fuction return the address of the first accurense of one of the 
//of charser in the string str
char	*ft_strchrset(char *str, char *charset)
{
	while (str)
	{
		if (ft_strchr(charset, *str))
			return (str);
		str++;
	}
	return (NULL);
}
