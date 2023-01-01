/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:50:47 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/11/06 23:27:15 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

static char	check_error(void)
{
	errno = EOVERFLOW;
	return (-1);
}

// int ft_atol(const char *str)
// The atol() function converts the initial portion of the string 
	// pointed to by str to int,
// on sucess the number is returned on overflow -1 is returned and 
	// errno is set to indecate the error.
int	ft_atoi(const char *str)
{
	char	digit;
	char	sign;
	int		final;

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
		if ((final > INT_MAX / 10 || (final == INT_MAX / 10 && digit > 7)) \
			|| (final < INT_MIN / 10 || (final == INT_MIN / 10 && digit < -8)))
			return (check_error());
		final = (final * 10) + digit;
		str++;
	}
	return (final);
}
