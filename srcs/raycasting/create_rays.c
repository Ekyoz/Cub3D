/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:40:07 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 16:40:07 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static t_vector_f interpolate(t_vector_f start, t_vector_f end, float interpolate_value);

void create_rays(t_cub *cub)
{
	t_vector_f fov_vect[2];
	t_vector_f vector;
	double direction;
	double interpolate_value;
	int	direction_len;
	int i;

	i = -1;
	direction = get_direction(vector_f_to_d(cub->player.pos), cub->player.view_dst_pos);

	direction_len = tan(degree_to_radian(FOV / 2)) * VIEW_DIST;

	fov_vect[0] = create_vect_f_from_origin(vector_d_to_f(cub->player.view_dst_pos), direction + PI_2, direction_len);
	fov_vect[1] = create_vect_f_from_origin(vector_d_to_f(cub->player.view_dst_pos), direction - PI_2, direction_len);

	interpolate_value = 1.0f / (cub->rays_nb - 1.0f);
	while (++i < cub->rays_nb)
	{
		vector = interpolate(fov_vect[0], fov_vect[1], interpolate_value * i);
		cub->rays[i].angle = get_direction_f(cub->player.pos, vector);
		cub->rays[i].hit_point = vector;
	}
}

static t_vector_f interpolate(t_vector_f start, t_vector_f end, float interpolate_value)
{
	t_vector_f vector;

	vector.x = start.x + (end.x - start.x) * interpolate_value;
	vector.y = start.y + (end.y - start.y) * interpolate_value;
	return (vector);
}