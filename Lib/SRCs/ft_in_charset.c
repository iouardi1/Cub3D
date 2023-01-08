/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:02:57 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/06 18:02:57 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../cub_lib.h"

/*checks if the string str contains only chars from the charset
return 0 if the string contains only chars from charset 
and diffrent to " > 0" if the str contain a char out of charset 
*/
int	ft_in_charset(char *str, char *charset)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	if (str[i] == '\0')
		return (-1);
	while (str[i] && ft_strchr(charset, str[i]))
		i++;
	return (str[i]);
}
