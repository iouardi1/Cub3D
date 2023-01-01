/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:36:33 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:57:57 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

static unsigned char	check_error(void)
{
	errno = EOVERFLOW;
	return (0);
}

// unsigned long ft_atoul(const char *str)
// The atoul() function converts the initial portion of the string 
	// pointed to by str to unsigned long,
// on sucess the number is returned on overflow 0 is returned and 
	// errno is set to indecate the error.
unsigned long	ft_atoul(const char *str)
{
	unsigned long	final;
	char			digit;

	final = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		digit = (*str - '0');
		if (final > ULLONG_MAX / 10 || (final == ULONG_MAX / 10 && digit > 5))
			return (check_error());
		final = (final * 10) + digit;
		str++;
	}
	return (final);
}
