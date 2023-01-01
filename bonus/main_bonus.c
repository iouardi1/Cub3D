/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:13:56 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/11/06 22:57:13 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub_bonus.h"

int	main(int ac, char **av)
{
	t_data	*game_data;

	if (ac != 2)
	{
		ft_putstr_fd("error wrong arguments count\n", 2);
		return (EXIT_FAILURE);
	}
	game_data = ft_calloc(sizeof(t_data), 1);
	game_data->vis_settings.cv = ft_calloc(3, sizeof(int));
	game_data->vis_settings.fv = ft_calloc(3, sizeof(int));
	if (parsing(game_data, av))
		return (EXIT_FAILURE);
	to_3d(game_data);
	return (EXIT_SUCCESS);
}
