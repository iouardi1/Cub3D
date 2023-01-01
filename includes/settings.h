/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:23:00 by achedmi           #+#    #+#             */
/*   Updated: 2022/11/06 21:20:48 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# define WINDOW_W                   1920
# define WINDOW_H                   1080

// # define WINDOW_W                   1280
// # define WINDOW_H                   960

// # define WINDOW_W                   640
// # define WINDOW_H                   480

// # define WINDOW_W                   320
// # define WINDOW_H                   200

// # define BLOCK_SIZE		128
# define BLOCK_SIZE		64
// # define BLOCK_SIZE		50

// # define MINI_MAP_W                 800
// # define MINI_MAP_H                 400

// # define WALL_COLOR                 0x3a6d92
// # define GROUND_COLOR               0x063aa73
// # define PLAYER_COLOR               0xFF0000

# define GROUND                     0
# define WALL                       1
# define PLAYER                     2
# define EMPTY                      3

// # define STEP_SIZE                  1
# define STEP_SIZE                  20

// # define ROTAION_DEG                0.002
# define ROTAION_DEG                0.1

# include "global_includes.h"
# include "cub.h"

#endif
