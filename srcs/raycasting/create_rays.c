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

void create_rays(t_cub *cub)
{
	t_vector_f vect_opposite[2];

	double angle = get_angle(vector_f_to_d(cub->player.pos), cub->player.view_dst_pos);

	t_vector_d view_dst_pos = create_vect_d_from_origin(vector_f_to_d(cub->player.pos), angle, VIEW_DIST);
	draw_circle_color_radius(cub, view_dst_pos, GREEN, 4);

	int opposite_len = tan(degree_to_radian(FOV / 2)) * VIEW_DIST;

	vect_opposite[0] = create_vect_f_from_origin(vector_d_to_f(view_dst_pos), angle + PI_2, opposite_len);
	vect_opposite[1] = create_vect_f_from_origin(vector_d_to_f(view_dst_pos), angle - PI_2, opposite_len);

//	bresenham(cub, vector_f_to_d(cub->player.pos), cub->mouse.pos, YELLOW);
	draw_circle_color_radius(cub, vector_f_to_d(vect_opposite[0]), BLUE, 4);
	draw_circle_color_radius(cub, vector_f_to_d(vect_opposite[1]), RED, 4);

	double inter = 1.0f / (cub->rays_nb - 1.0f);

	for (int i = 0; i < cub->rays_nb; ++i) {
		t_vector_f ray_end = vector_f_lerp(vect_opposite[0], vect_opposite[1], inter * i);
		cub->rays[i].angle = get_angle_f(cub->player.pos, ray_end);
		cub->rays[i].hit_point = ray_end;
	}
}