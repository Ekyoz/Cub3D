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

void	create_rays(t_cub *cub)
{
	double		angle;
	t_vector_d	v_dst;
	double		inter;
	int			i;
	t_vector_f	ray_end;

	angle = get_angle(vector_f_to_d(cub->player.pos), cub->player.view_dst_pos);
	v_dst = create_vect_d_from_origin(vector_f_to_d(cub->player.pos),
			angle, VIEW_DIST);
	inter = 1.0f / (cub->rays_nb - 1.0f);
	i = 0;
	while (i < cub->rays_nb)
	{
		ray_end = vector_f_lerp(create_vect_f_from_origin(vector_d_to_f(v_dst),
					angle + PI_2, tan(degree_to_radian(FOV / 2)) * VIEW_DIST),
				create_vect_f_from_origin(vector_d_to_f(v_dst), angle
					- PI_2, tan(degree_to_radian(FOV / 2)) * VIEW_DIST), inter
				* i);
		cub->rays[i].angle = get_angle_f(cub->player.pos, ray_end);
		cub->rays[i].hit_point = ray_end;
		i++;
	}
}
