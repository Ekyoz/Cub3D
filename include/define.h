/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:19:40 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/09 17:42:47 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "error_messages.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

// WINDOWS SETTINGS

# define WIDTH 1440
# define HEIGHT 900

// MAP SETTINGS
# define TILE_SIZE 40
# define MAP_ZOOM 8
# define SIZE_MAP 5

// VIEW SETTINGS
# define FOV 66
# define VIEW_DIST 500

// SPEED
# define MOVE_SPEED 2
# define ROT_SPEED_KEY 0.045f
# define ROT_SPEED_MOUSE 500.0f

// MATHS
# define PI 3.14
# define PI_2 1.57

// MLX Colors
# define WHITE 0x00FFFFFF
# define DARK_GRAY 0x00222222
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define YELLOW 0x00FFFF00
# define PINK 0x00DD88BB

// KEYS LINUX
//# define LMB 1
//# define RMB 3
//# define KEY_E 101
//# define KEY_ESC 65307 % 200
//# define KEY_UP 65362 % 200
//# define KEY_DOWN 65364 % 200
//# define KEY_LEFT 65361 % 200
//# define KEY_RIGHT 65363 % 200
//# define KEY_W 119 % 200
//# define KEY_S 115 % 200
//# define KEY_A 97 % 200
//# define KEY_D 100 % 200
//# define KEY_TAB 65289 % 200

// KEY MAC
# define LMB 1
# define RMB 2
# define KEY_TAB 48
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_E 14
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

#endif
