/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:03:58 by achedmi           #+#    #+#             */
/*   Updated: 2023/01/12 05:58:11 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

int	main(int ac, char **av)
{
	t_data	*game_data;

	if (ac != 2)
	{
		ft_putstr_fd("error wrong arguments count\n", 2);
		return (1);
	}
	game_data = ft_calloc(sizeof(t_data), 1);
	game_data->vis_settings.cv = ft_calloc(3, sizeof(int));
	game_data->vis_settings.fv = ft_calloc(3, sizeof(int));
	if (parsing(game_data, av))
		return (1);
	to_3d(game_data);
	return (0);
}
