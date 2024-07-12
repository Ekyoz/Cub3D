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

#include "cub3d.h"

static void	print_map(t_cub *cub, t_vector_f dda_vec, int i);

void	rays_collisions(t_cub *cub)
{
	t_vector_f	dda_vec;
	int			i;

	i = 0;
	while (i < cub->rays_nb)
	{
		dda_vec = dda(cub, &cub->rays[i]);
		print_map(cub, dda_vec, i);
		if (dda_vec.x != -1 && dda_vec.y != -1)
		{
			cub->rays[i].hit_point = dda_vec;
			cub->rays[i].length = get_vector_f_length(cub->player.pos, dda_vec);
		}
		else
		{
			cub->rays[i].perp_length = -1;
			cub->rays[i].hit_point = create_vect_f_from_origin(cub->player.pos,
					get_angle_f(cub->player.pos, cub->rays[i].hit_point),
					VIEW_DIST);
		}
		i++;
	}
}

static void	print_map(t_cub *cub, t_vector_f dda_vec, int i)
{
	t_vector_f	ray_full_dst;

	if (dda_vec.x != -1 && dda_vec.y != -1)
	{
		if (cub->player.map)
			bresenham(cub, vector_f_to_d(cub->player.pos),
				vector_f_to_d(dda_vec), WHITE);
	}
	else
	{
		if (cub->player.map)
		{
			ray_full_dst = create_vect_f_from_origin(cub->player.pos,
					get_angle_f(cub->player.pos, cub->rays[i].hit_point),
					VIEW_DIST);
			bresenham(cub, vector_f_to_d(cub->player.pos),
				vector_f_to_d(ray_full_dst), YELLOW);
		}
	}
}
