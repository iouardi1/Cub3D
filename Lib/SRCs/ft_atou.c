/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:02:32 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/06 18:02:33 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../cub_lib.h"

static unsigned char	check_error(void)
{
	errno = EOVERFLOW;
	return (0);
}

// unsigned int ft_atoul(const char *str)
// The atou() function converts the initial portion of the string 
	// pointed to by str to unsigned int,
// on sucess the number is returned on overflow 0 is returned and 
	// errno is set to indecate the error.
unsigned int	ft_atou(const char *str)
{
	unsigned int	final;
	char			digit;

	final = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		digit = (*str - '0');
		if (final > UINT_MAX / 10 || (final == UINT_MAX / 10 && digit > 5))
			return (check_error());
		final = (final * 10) + digit;
		str++;
	}
	return (final);
}
