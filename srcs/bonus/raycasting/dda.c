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

static t_vector_f	calculate_delta_dist(t_vector_f ray_dir);
static void			initialize_steps_and_side_dist(t_cub *cub, t_ray *ray,
						t_vector_d map, t_vector_f vect_list[3]);
static t_vector_f	traverse_ray(t_cub *cub, t_ray *ray, t_vector_d map,
						t_vector_f vect_list[3]);
static t_vector_f	handle_collision(t_ray *ray, t_vector_d map,
						t_vector_f vect_list[3], t_vector_d side_hit);

t_vector_f	dda(t_cub *cub, t_ray *ray)
{
	t_vector_d	map;
	t_vector_f	vect_list[3];

	ray->ray_dir = ray->hit_point;
	map = vector_f_to_d(cub->player.pos);
	ray->ray_dir.x = ray->ray_dir.x - cub->player.pos.x;
	ray->ray_dir.y = ray->ray_dir.y - cub->player.pos.y;
	vect_list[0] = calculate_delta_dist(ray->ray_dir);
	initialize_steps_and_side_dist(cub, ray, map, vect_list);
	return (traverse_ray(cub, ray, map, vect_list));
}

static t_vector_f	calculate_delta_dist(t_vector_f ray_dir)
{
	t_vector_f	vect_list;

	if (ray_dir.x == 0.0f)
		vect_list.x = 1e30;
	else
		vect_list.x = ft_abs_f(1.0f / ray_dir.x);
	if (ray_dir.y == 0.0f)
		vect_list.y = 1e30;
	else
		vect_list.y = ft_abs_f(1.0f / ray_dir.y);
	return (vect_list);
}

static void	initialize_steps_and_side_dist(t_cub *cub, t_ray *ray,
		t_vector_d map, t_vector_f vect_list[3])
{
	if (ray->ray_dir.x < 0)
	{
		vect_list[2].x = -1;
		vect_list[1].x = (cub->player.pos.x - map.x) * vect_list[0].x;
	}
	else
	{
		vect_list[2].x = 1;
		vect_list[1].x = (map.x + 1.0f - cub->player.pos.x) * vect_list[0].x;
	}
	if (ray->ray_dir.y < 0)
	{
		vect_list[2].y = -1;
		vect_list[1].y = (cub->player.pos.y - map.y) * vect_list[0].y;
	}
	else
	{
		vect_list[2].y = 1;
		vect_list[1].y = (map.y + 1.0f - cub->player.pos.y) * vect_list[0].y;
	}
}

static t_vector_f	traverse_ray(t_cub *cub, t_ray *ray, t_vector_d map,
		t_vector_f vect_list[3])
{
	float		ray_length;
	t_vector_d	side_hit;

	ray_length = len_squared(vector_f_to_d(cub->player.pos), map);
	while (ray_length < VIEW_DIST * VIEW_DIST)
	{
		if (vect_list[1].x < vect_list[1].y)
		{
			vect_list[1].x += vect_list[0].x;
			map.x += vect_list[2].x;
			side_hit.x = vect_list[2].x;
			side_hit.y = 0;
		}
		else
		{
			vect_list[1].y += vect_list[0].y;
			map.y += vect_list[2].y;
			side_hit.x = 0;
			side_hit.y = vect_list[2].y;
		}
		ray_length = len_squared(vector_f_to_d(cub->player.pos), map);
		if (is_colliding_cell(cub, (float)map.x, (float)map.y, 0) == 1)
			return (handle_collision(ray, map, vect_list, side_hit));
	}
	return ((t_vector_f){-1, -1});
}

static t_vector_f	handle_collision(t_ray *ray, t_vector_d map,
		t_vector_f vect_list[3], t_vector_d side_hit)
{
	if (side_hit.y == 0)
		ray->perp_length = (vect_list[1].x - vect_list[0].x) * TILE_SIZE;
	else
		ray->perp_length = (vect_list[1].y - vect_list[0].y) * TILE_SIZE;
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
