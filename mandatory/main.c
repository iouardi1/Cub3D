/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:23:39 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/07 23:55:05 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

int main(int ac, char **av)
{
	t_data *game_data;

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
