/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_utiles.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:58:41 by achedmi           #+#    #+#             */
/*   Updated: 2022/11/12 15:19:35 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	conditions(t_visual_settings *vis_settings, t_index i)
{
	return (((char **)vis_settings)[i][0] == '\n' || \
				*(ft_strchr(((char **)vis_settings)[i], '\0') - 1) == '\n' || \
				check_for_char(((char **)vis_settings)[i], ',') || \
				((char **)vis_settings)[i][0] == ',' || \
				*(ft_strchr(((char **)vis_settings)[i], '\0') - 1) == ',' || \
				ft_in_charset(((char **)vis_settings)[i], "0123456789,"));
}
