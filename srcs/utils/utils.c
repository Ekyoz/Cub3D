/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:43:19 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/05 15:43:19 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int is_in_map(t_cub *cub, t_vector_d pos)
{
	if (pos.x < 0 || pos.x > cub->map.width - 1)
		return (0);
	if (pos.y < 0 || pos.y > cub->map.height - 1)
		return (0);
	return (1);
}

int		is_colliding_cell(t_cub *cub, float x, float y)
{
	t_vector_d	cell;

	cell = create_d_vect(x/TILE_SIZE, y/TILE_SIZE);
	if (!is_in_map(cub, create_d_vect(cell.x, cell.y)))
		return (0);
	if (cub->map.map[cell.y][cell.x] == '1') // Wall
		return (1);
	return (0);
}