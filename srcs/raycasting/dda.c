/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:51:24 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/02 11:51:24 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_vector_f dda(t_cub *cub, t_ray *ray)
{
	ray->ray_dir = ray->hit_point;
	t_vector_d map = vector_f_to_d(cub->player.pos); // Position used to check tab value

	t_vector_f side_dist; // Origin point offset to the nearest int positon
	t_vector_f delta_dist; // Length of the hyptenuse

	ray->ray_dir.x = ray->ray_dir.x - cub->player.pos.x;
	ray->ray_dir.y = ray->ray_dir.y - cub->player.pos.y;

	if (ray->ray_dir.x == 0.0f)
		delta_dist.x = 1e30; // Large value
	else
		delta_dist.x = ft_abs_f(1.0f / ray->ray_dir.x);
	if (ray->ray_dir.y == 0.0f)
		delta_dist.y = 1e30; // Large value
	else
		delta_dist.y = ft_abs_f(1.0f / ray->ray_dir.y);

	t_vector_d step;
	if (ray->ray_dir.x < 0)
	{
		step.x = -1; // Calculating X step (depending on the direction)
		side_dist.x = (cub->player.pos.x - map.x) * delta_dist.x; // Calculating X gap to the nearest integer coordinate
	}
	else
	{
		step.x = 1;
		side_dist.x = (map.x + 1.0f - cub->player.pos.x) * delta_dist.x;
	}

	if (ray->ray_dir.y < 0)
	{
		step.y = -1; // Calculating Y step (depending on the direction)
		side_dist.y = (cub->player.pos.y - map.y) * delta_dist.y; // Calculating Y gap to the nearest integer coordinate
	}
	else
	{
		step.y = 1;
		side_dist.y = (map.y + 1.0f - cub->player.pos.y) * delta_dist.y;
	}

	float ray_length = len_squared(vector_f_to_d(cub->player.pos), map);
	t_vector_d side_hit;

	while (ray_length < VIEW_DIST * VIEW_DIST)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			map.x += step.x;
			side_hit.x = step.x;
			side_hit.y = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			map.y += step.y;
			side_hit.x = 0;
			side_hit.y = step.y;
		}

		ray_length = len_squared(vector_f_to_d(cub->player.pos), map);

		if (is_colliding_cell(cub, (float)map.x, (float)map.y, 0) == 1)
		{
			if (side_hit.y == 0)
				ray->perp_length = (side_dist.x - delta_dist.x) * TILE_SIZE;
			else
				ray->perp_length = (side_dist.y - delta_dist.y) *TILE_SIZE;

			if (side_hit.x == 1)
				ray->side_hit = 3;
			else if (side_hit.x == -1)
				ray->side_hit = 1;
			else if (side_hit.y == 1)
				ray->side_hit = 0;
			else
				ray->side_hit = 2;

			set_vector_d(&ray->cell, map.x / TILE_SIZE, map.y / TILE_SIZE);

			return (vector_d_to_f(map));
		}
	}
	return ((t_vector_f){-1, -1});
}