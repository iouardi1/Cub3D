/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:02:28 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/06 18:02:28 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../cub_lib.h"

static char	check_error(void)
{
	errno = EOVERFLOW;
	return (-1);
}

// long ft_atol(const char *str)
// The atol() function converts the initial portion of the string 
	// pointed to by str to long,
// on sucess the number is returned on overflow -1 is returned and 
	// errno is set to indecate the error.
long	ft_atol(const char *str)
{
	char	digit;
	char	sign;
	long	final;

	final = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		digit = (*str - '0') * sign;
		if ((final > LONG_MAX / 10 || (final == LONG_MAX / 10 && digit > 7)) || \
			(final < LONG_MIN / 10 || (final == LONG_MIN / 10 && digit < -8)))
			return (check_error());
		final = (final * 10) + digit;
		str++;
	}
	return (final);
}
