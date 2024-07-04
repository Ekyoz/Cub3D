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

static void	plot_line_high(t_cub *data, t_vector_d p1, t_vector_d p2, int color);
static void	plot_line_low(t_cub *data, t_vector_d p1, t_vector_d p2, int color);

void	bresenham(t_cub *data, t_vector_d p1, t_vector_d p2, int color)
{
	if (abs(p2.y - p1.y) < abs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			plot_line_low(data, p2, p1, color);
		else
			plot_line_low(data, p1, p2, color);
	}
	else
	{
		if (p1.y > p2.y)
			plot_line_high(data, p2, p1, color);
		else
			plot_line_high(data, p1, p2, color);
	}
}

static void	plot_line_high(t_cub *data, t_vector_d p1, t_vector_d p2, int color)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	int xi = 1;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int d = 2 * dx - dy;
	int x = p1.x;

	// Calculating const
	int cst1 = 2 * (dx - dy);
	int cst2 = 2 * dx;

	for (int y = p1.y; y < p2.y; y++)
	{
		my_mlx_pixel_put(&data->mlx, x, y, color);
		if (d > 0)
		{
			x += xi;
			d += cst1;
		}
		else
			d += cst2;
	}
}

static void	plot_line_low(t_cub *data, t_vector_d p1, t_vector_d p2, int color)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	int yi = 1;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int d = 2 * dy - dx;
	int y = p1.y;

	// Calculating const
	int cst1 = 2 * (dy - dx);
	int cst2 = 2 * dy;

	for (int x = p1.x; x < p2.x; x++)
	{
		my_mlx_pixel_put(&data->mlx, x, y, color);
		if (d > 0)
		{
			y += yi;
			d += cst1;
		}
		else
			d += cst2;
	}
}

void rays_collisions(t_cub *cub)
{
	t_vector_f rays;
	int i;

	i = -1;
	while (++i < cub->rays_nb)
	{
		rays = dda(cub, &cub->rays[i]);

		if (rays.x != -1 && rays.y != -1)
		{
			cub->rays[i].hit_point = rays;
			cub->rays[i].length = get_vector_f_length(cub->player.pos, rays);
			if (cub->player.map == 1)
				bresenham(cub, vector_f_to_d(cub->player.pos), vector_f_to_d(rays), YELLOW);
		}
		else
		{
			cub->rays[i].perp_length = -1;
			if (cub->player.map == 1)
			{
				// Setting the vector length to view_dst (to create the "rounded" effect in fov display)
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