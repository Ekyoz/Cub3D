/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:40:03 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/02 12:40:03 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void set_floor_cell(t_cub *cub)
{
	int floor_start  = WIDTH * (HEIGHT / 2 + cub->mouse.move.y);
	int total = WIDTH * HEIGHT;
	int size = cub->mlx.bits_per_pixel / 8;
	int i = -1;
	char *dst;

	while (++i < floor_start)
	{
		dst = cub->mlx.addr + i * size;
		*(unsigned int *)dst = cub->map.textures.ceiling;
	}

	i = floor_start - 1;

	while (++i < total)
	{
		dst = cub->mlx.addr + i * size;
		*(unsigned int *)dst = cub->map.textures.floor;
	}
}