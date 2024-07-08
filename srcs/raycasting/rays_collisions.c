/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_collisions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:49:26 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/02 11:49:26 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void rays_collisions(t_cub *cub)
{
	t_vector_f dda_vec;

	for (int i = 0; i < cub->rays_nb; ++i)
	{
		 dda_vec = dda(cub, &cub->rays[i]);

		 if (dda_vec.x != -1 && dda_vec.y != -1)
		 {
			 cub->rays[i].hit_point = dda_vec;
			 cub->rays[i].length = get_vector_f_length(cub->player.pos, dda_vec);
			 if (cub->player.map == 1)
				 bresenham(cub, vector_f_to_d(cub->player.pos), vector_f_to_d(dda_vec), WHITE);
		 }
		 else
		 {
			 cub->rays[i].perp_length = -1;
			 cub->rays[i].hit_point = create_vect_f_from_origin(cub->player.pos, get_angle_f(cub->player.pos, cub->rays[i].hit_point), VIEW_DIST);
			 if (cub->player.map == 1)
			 {
				 t_vector_f ray_full_dst = create_vect_f_from_origin(
						 cub->player.pos,
						 get_angle_f(cub->player.pos, cub->rays[i].hit_point),
						 VIEW_DIST
				 );
			 	bresenham(cub, vector_f_to_d(cub->player.pos), vector_f_to_d(ray_full_dst), YELLOW);
			 }
		 }
	}
}